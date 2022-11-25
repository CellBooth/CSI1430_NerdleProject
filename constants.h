/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "color.h"

//for window size
const int NUM_ROW = 800; //THIS WAS 800

//for the number of rows of tiles printed on the mainboard
const int BOX_ROW = 6;
//const int BOX_COL = 12;

//specs of boxes that will be printed
const int TILE_HEIGHT = 64;
const int TILE_WIDTH = 70;
const int TILE_GAP = 8; //space between tiles
const int TILE_LEFTSPACE = 8; //space from the left-most tile to left border
const int TILE_UPPERSPACE = 150; //space above tiles

#endif // CONSTANTS_H_INCLUDED
