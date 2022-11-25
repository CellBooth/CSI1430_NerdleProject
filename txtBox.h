/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
//object is a grouping of information necessary to print to the screen

#include "color.h"
#include "point.h"

struct txtBox {
  string textFileName;
  color_t color;
  int height, width;
  point location;
  txtBox(string textFileName = "NULL", color_t color = GREEN, int height = 0, int width = 0, int x = 0, int dimension = 500, int y = 0){
    this-> textFileName = textFileName;
    this-> color = color;
    this-> height = height;
    this-> width = width;
    this-> location.setX(x, dimension);
    this-> location.setY(y);
}

};

#endif // OBJECTS_H_INCLUDED
