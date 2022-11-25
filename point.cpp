/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#include "point.h"
#include "constants.h"


point::point(int x, int y){
    setX(x);
    setY(y);
}
void point::setX(int x, int xWinDimension){
    if(x >= 0 && x < xWinDimension){
        this->x = x;
    }
}
void point::setY(int y){
    if(y >= 0 && y < NUM_ROW){
       this->y = y;
    }
}
int point::getX() const{
    return x;
}
int point::getY() const{
    return y;
}

