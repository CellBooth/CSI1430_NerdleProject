/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */



#ifndef DOESITCOMPUTE_H_INCLUDED
#define DOESITCOMPUTE_H_INCLUDED

#include "EquationBuilder.h"

using namespace std;

//************************************************************
// description: checks whether a user guess computes         *
// return: bool                                              *
// precondition: a string exists                             *
// postcondition: input string is unchanged. Function returns*
//    1 if the user input a valid guess and 0 otherwise      *
//************************************************************

bool DoesItCompute(const string);

#endif // DOESITCOMPUTE_H_INCLUDED
