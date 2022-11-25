/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef POSTGUESSCOLORSET_H_INCLUDED
#define POSTGUESSCOLORSET_H_INCLUDED



#include <vector>
#include <iostream>
#include <string>

using namespace std;

//************************************************************
// description: takes in a character and returns which index *
//    a outside vector contains that relates to said char    *
// return: int                                               *
// precondition: input char given which is any of 0-9, +, -, *
//    *, /                                                   *
// postcondition: function returns the index to increment    *
//    based on given character                               *
//************************************************************

int frequency(char);

//************************************************************
// description: takes in the user's guess as a string and the*
//    correct equation string. Then returns the correct      *
//    colors for the tiles the user's guess is displayed on  *
// return: vector of strings                                 *
// precondition: the user's current guess and the correct    *
//    equation are given as parameter arguments              *
// postcondition: function returns a vector of strings       *
//    where each index relates to the column on the current  *
//    row being guessed                                      *
//************************************************************

vector<string> PostguessColorSet(string, string );

#endif // POSTGUESSCOLORSET_H_INCLUDED
