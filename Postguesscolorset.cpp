/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */

#include "Postguesscolorset.h"


int frequency(char option){
   int returnval;
   //switch statement takes the char input and
   //returns the correct index of a vector to be incremented
   //That relates to input character
   switch(option){
      case '0':
         returnval = 0;
         break;
      case '1':
         returnval = 1;
         break;
      case '2':
         returnval = 2;
         break;
      case '3':
         returnval = 3;
         break;
      case '4':
         returnval = 4;
         break;
      case '5':
         returnval = 5;
         break;
      case '6':
         returnval = 6;
         break;
      case '7':
         returnval = 7;
         break;
      case '8':
         returnval = 8;
         break;
      case '9':
         returnval = 9;
         break;
      case '+':
         returnval = 10;
         break;
      case '-':
         returnval = 11;
         break;
      case '*':
         returnval = 12;
         break;
      case '/':
         returnval = 13;
         break;
      case '=':
         returnval = 14;
         break;
   }
   return returnval;
}

vector <string> PostguessColorSet(string correctEq, string userEq){
   vector <string> userEqColor(correctEq.size());
   vector <int> correctEqFreq(15,0), userEqFreq(15,0);
   //does all for green
   //colors are full words in all caps as elsewhere the same
   //full cap words are constants for the tile color so
   //returning in this form lets us reference those colors
   //from the return vector and takes out a conversion step
   //in the overall Nerdle program

   for(unsigned int i = 0; i < correctEq.size();i++){
      if(correctEq.at(i) == userEq.at(i)){
         userEqColor.at(i) = "GREEN";
         userEqFreq.at(frequency(userEq.at(i)))++;
      }
      correctEqFreq.at(frequency(correctEq.at(i)))++;
   }
   //does purple
   for(unsigned int i = 0; i < correctEq.size(); i ++){
      //skips over spaces already labeled GREEN as the frequency
      //for these have already been counted
      if(userEqColor.at(i) != "GREEN"){
         //vector indexes without a color can only be purple or black
         //so we check for purple and if not it must be black
         if(userEqFreq.at(frequency(userEq.at(i))) < correctEqFreq.at(frequency(userEq.at(i)))){
            userEqColor.at(i) = "PURPLE";
         }else{
            userEqColor.at(i) = "BLACK";
         }
         userEqFreq.at(frequency(userEq.at(i)))++;
      }
   }

   return userEqColor;
}





