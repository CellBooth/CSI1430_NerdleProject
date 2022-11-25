/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */

#include "DoesItCompute.h"
#include <iostream>

bool DoesItCompute(const string userInput){
   int equalIndex = -1;
   bool computes = 1;
   int count = 0;
   string leftOfEqual, rightOfEqual;
   //Finds the last = in string
   for (int v = 0; v < userInput.size(); v++){
      if(userInput.at(v) == '='){
         equalIndex = v;
         count++;
      }
   }
   //Only runs if string has only 1 equal sign
   if( count == 1){
      //makes a string that is the substring of left side of input
      //   up to the equal sign
      for (int v = 0; v < equalIndex; v++){
         leftOfEqual.push_back(userInput.at(v));
          if((userInput.at(v) < '0' || userInput.at(v) > '9') && userInput.at(v) != '+' && userInput.at(v) != '-' && userInput.at(v) != '*' && userInput.at(v) != '/'){
            computes = 0;
         }
      }
      //makes a string of everything to the right of the equal sign in
      //   input string
      for (int v = equalIndex + 1; v < userInput.size(); v++){
         rightOfEqual.push_back(userInput.at(v));
         //Guards against anything other than digits being on the right side
         if(userInput.at(v) < '0' || userInput.at(v) > '9'){
            computes = 0;
         }
      }
      //Checks to see if the left and right are mathematically equal
      if(Op1Evaluate(leftOfEqual) != rightOfEqual){
         computes = 0;
      }
   }else{
      computes = 0;
   }
   return computes;
}
