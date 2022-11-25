/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef TXTDRAW_H_INCLUDED
#define TXTDRAW_H_INCLUDED

#include <string>
#include <fstream>
#include "SDL_Plotter.h"
#include "tile.h"
#include "constants.h"
#include "txtBox.h"
#include "color.h"
using namespace std;


//************************************************************
// description: takes a char and returns the txt file name   *
//    needed to draw it                                      *
// return: string                                            *
// precondition: valid char given                            *
// postcondition: function returns string that is name of    *
//    proper txt file                                        *
//************************************************************

string charToFile(char);

//************************************************************
// description: uses input of a fieName,plotter, and tile    *
//    to plot correct char at correct spot                   *
//    appropriate pixels based on input file                 *
// return: void                                              *
// precondition: valid fileName                              *
// postcondition: function plots all 1's in txt file to      *
//    proper location                                        *
//************************************************************

void drawTxt (char, SDL_Plotter&, tile box);

//************************************************************
// description: prints a white box to the SDL_Plotter        *
//     where the dialog boxes appear under the tiles         *
// return: void                                              *
// precondition: valid plotter given                         *
// postcondition: the area where dialog boxes can be switched*
//     out gets whited out so multiple boxes don't appear at *
//     once                                                  *
//************************************************************
void whiteOutBottom (SDL_Plotter&);

//************************************************************
// description: prints a white box to the SDL_Plotter        *
//     where the dialog boxes appear above the tiles         *
// return: void                                              *
// precondition: valid plotter given                         *
// postcondition: the area above the tiles gets whited out   *
//     to allow for switching dialog                         *
//************************************************************
void whiteOutTop(SDL_Plotter&);
//************************************************************
// description: prints to the SDL_Plotter based on the data  *
//     in a txtBox object                                    *
// return: void                                              *
// precondition: valid SDL_Plotter, txtBox, and color_t      *
//     are given as parameters                               *
// postcondition: the txtBox is printed the SDL_Plotter      *
//************************************************************

void drawObject(SDL_Plotter&, txtBox , color_t);

#endif // TXTDRAW_H_INCLUDED
