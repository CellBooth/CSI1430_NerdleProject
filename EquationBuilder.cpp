/*
 * Author: Cole Flenniken
 * Assignment Title: Nerdle
 * Assignment Description: build a string
 *    that is an equation with specified size
 * Due Date: end of semester
 * Date Created: 3/20/22
 * Date Last Modified: 3/30/22
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "EquationBuilder.h"


using namespace std;

int rSide,lSide,a = 0,currIndex = 0;
int place = 1, keepGoing,newIndex, answer = 0, i;
string toReplace ="", evaluate = "";
bool goodData = 1;


string EquationGenerator(int SizeOfEquation){
 string exp1 = "";
 string exp2 = "";
 string finalEquation;

 int notLong = 1;
 int lengthOfEquation;
 const string options = "1234567890+-*/";
 if(SizeOfEquation > 5){
 srand(time(0));
 exp1 = options.at(rand()% 9);
 while(notLong == 1 ){

   exp1.push_back(options.at(rand()% 14));
   if (exp1.at(exp1.size()-1) < 48 ){
      exp1.push_back(options.at(rand()% 9));
   }
   lengthOfEquation = Op1Evaluate(exp1).size() + exp1.size() + 1;
   if(lengthOfEquation > SizeOfEquation || Op1Evaluate(exp1) == "BADMATH"){
      //indicates to restart string
      exp1 = "";
      exp1.push_back(options.at(rand()% 9));
   }else if (lengthOfEquation == SizeOfEquation){
      //Indicates string is right size
      notLong = 0;
      exp2 = Op1Evaluate(exp1);

   }

 }
 //final equation consists of the left side expression
 //an equality character and the right side expression which
 //was created by evaluating the left side expression
 finalEquation = exp1 + '=' + exp2;
 }else{
    finalEquation = "TOOSMALLPERAMETER";
 }
 return finalEquation;
}

 void lSideFind(){
   place = 1;
   for (int y = i - 1; y >= 0 && (evaluate.at(y) > 47 && evaluate.at(y) < 58); --y){
      if (place == 1){
         lSide = evaluate.at(y) - 48;
         place = place * 10;
      }else{
         lSide = lSide + (place * (evaluate.at(y) - 48));
         place = place * 10;
      }
      //this is later used to indicate where to start replacing a substring
      a = y;
   }
}

//Finds value of right side of operator
void rSideFind(){
   for (int y = i + 1; y < evaluate.length(); y++){
      if (evaluate.at(y) == '*' || evaluate.at(y) == '/' ||  evaluate.at(y) == '+' ||  evaluate.at(y) == '-'){
         newIndex = y -1;
         y = evaluate.length() ;
      }else if(y == evaluate.length()- 1){
         newIndex = y;
      }
   }
   place = 1;

   for (int y = newIndex  ; y >= 0 && (evaluate.at(y) > 47 && evaluate.at(y) < 58); --y){

      if (place == 1){
         rSide = evaluate.at(y) - 48;
         place = place * 10;
      }else {

         rSide = rSide + (place * (evaluate.at(y) - 48));
         place = place * 10;
      }
   }
}

//Checks whether to do *, +, - or /

void evaluateDivision(){
   lSideFind();
   rSideFind();
      answer = lSide / rSide;
      if((lSide % rSide) != 0){
         goodData = 0;
      }
      //May need to add guard for divide by 0
}


void evaluateMultiplication(){
      lSideFind();
      rSideFind();
      answer = lSide * rSide;
   }


void evaluateAddition(){
      lSideFind();
      rSideFind();
      answer = lSide + rSide;
   }


void evaluateSubtraction(){
      lSideFind();
      rSideFind();
      answer = lSide - rSide;
      if (rSide > lSide){
         goodData = 0;
      }
   }

void checkForOperator(){
      while( i < evaluate.size() && evaluate.at(i) != '/' && evaluate.at(i)!= '*'){
      i++;
   }
   if(i >= evaluate.size()){
      i = 0;
      while(i < evaluate.size() && evaluate.at(i)!= '+' && evaluate.at(i)!= '-' ){
         i++;
      }
   }
}
string Op1Evaluate(const string exp1eval){
   //Function alerts for divide by zero and decimals caused by division
   //Not guarded for two+ operants together as input function should not allow for this
   //If your program does not ensure that 2+ operants cannot be together then you
   //will need to modify this code

   evaluate = exp1eval;
   do{
      i = 0;
      keepGoing = 0;
      goodData =1;
      //function checks to see if operator is present and follows PEMDAS
      checkForOperator();
      //Does math based on what operator is present
      if(i < evaluate.size()){
         keepGoing = 1;
         switch (evaluate.at(i)){
            case '/':
               evaluateDivision();
               break;
            case '*':
               evaluateMultiplication();
               break;
            case '+':
               evaluateAddition();
               break;
            case '-':
               evaluateSubtraction();
               break;
         }
      }
      //The following lines first convert the answer of the math operation done
      //from an integer to a string. Then it takes that answer and replaces what was
      //evaluated with its answer.
      toReplace = to_string(answer);
      if(i < evaluate.size()){
      evaluate.replace(a, newIndex-a +1 , toReplace);
      }
      //This loop checks if any * or / operators are still present
      //in the string and sets a variable to true that a while loop later uses
      //so that it will run again.
      if(evaluate.at(0) == '-'){
         goodData = 0;
      }
   }while(keepGoing == 1 && goodData == 1);
   //this runs if division was done that resulted in a decimal
   //As all math done is integers decimals are not allowed
   if(goodData == 0 ){
      evaluate = "BADMATH";
   }
   return evaluate;
}


