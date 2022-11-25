/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED


struct color_t{
    int R, G, B;

    color_t(int r = 0, int g = 0, int b = 0){
        R = r;
        G = g;
        B = b;
    }
};


const color_t BLACK(0,0,0);
const color_t CBLACK(22,24,3);
const color_t GREY(155,155,155);
const color_t CGREY(152,148,132);
const color_t GREEN(57,136,116);
const color_t PURPLE(130,4,88);
const color_t CWHITE(255,255,255);
#endif // COLOR_H_INCLUDED
