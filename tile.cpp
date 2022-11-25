/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#include "tile.h"
#include "color.h"
tile::tile(){
    width = 50;
    height = 50;
    letter = ' ';
    location.setX(20);
    location.setY(20);
}

void tile::setLocation(const point& pt){
    location = pt;
}

void tile::setColor(const string a){

    color = strToCol(a);
}

void tile::setHeight(int input){
    height = input;
}

void tile::setWidth(int input){
    width = input;
}

void tile::setLetter(char input){
    letter = input;
}

point tile::getLocation() const{
    return location;
}

color_t tile::getColor() const{
    return color;
}

int tile::getHeight() const{
    return height;
}

int tile::getWidth() const{
    return width;
}

char tile::getLetter() const{
    return letter;
}

void tile::draw(SDL_Plotter& g) const{
    for(int x = 0; x < width; ++x){
        for(int y = 0; y < height; ++y){
           int checkX = x;
           int checkY = y;
           if(checkX > TILE_WIDTH / 2){
              checkX = checkX - TILE_WIDTH + 1;
           }
           if (checkY > TILE_HEIGHT / 2){
               checkY = checkY - TILE_HEIGHT + 1;
           }

           if(pow(checkX,2) + pow(checkY,2) > 4){
               g.plotPixel(location.getX() + x, location.getY() + y, color.R, color.G, color.B);
           }
        }
    }
}

color_t tile::strToCol(const string a){
    color_t returnVal;

    if(a == "GREEN"){
       returnVal = GREEN;
       }
       else if(a == "PURPLE"){
       returnVal = PURPLE;
       }
       else if(a == "CBLACK"){
       returnVal = CBLACK;
       }
       else if(a == "CGREY"){
       returnVal = CGREY;
     }
    return returnVal;
}
