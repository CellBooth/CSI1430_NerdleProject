/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <cmath>
#include <string>
#include <vector>
#include "point.h"
#include "SDL_Plotter.h"
#include "color.h"
#include "constants.h"

class tile{
    private:
        point location;
        color_t color;
        int height, width;
        char letter;
    public:
        tile();

        /*
        * description: sets the location of the tile
        * return: void
        * precondition: none
        * postcondition: the point is set
        */
        void setLocation(const point&);

        /*
        * description: sets the color of the tile
        * return: void
        * precondition: none
        * postcondition: the color is set
        */
        void setColor(const string);

        /*
        * description: sets the height of the tile
        * return: void
        * precondition: none
        * postcondition: the height is set
        */
        void setHeight(int = 50);

        /*
        * description: sets the width of the tile
        * return: void
        * precondition: none
        * postcondition: the width is set
        */
        void setWidth(int);

        /*
        * description: sets the letter printed on the tile
        * return: void
        * precondition: none
        * postcondition: the letter is set
        */
        void setLetter(char);

        /*
        * description: converts an input string to a color object
        * return: color_t
        * precondition: none
        * postcondition: a color_t object
        */
        color_t strToCol(const string);

        /*
        * description: gets the tile location
        * return: point
        * precondition: tile object exists
        * postcondition: the tile location is returned
        */
        point getLocation() const;

        /*
        * description: gets the color of the tile
        * return: color_t
        * precondition: tile object exists
        * postcondition: color of tile is returned
        */
        color_t getColor() const;

        /*
        * description: gets the height of the tile
        * return: int
        * precondition: tile object exists
        * postcondition: the tile height is returned
        */
        int getHeight() const;

        /*
        * description: gets the width of the tile
        * return: int
        * precondition: tile object exists
        * postcondition: returns the tile width
        */
        int getWidth() const;

        /*
        * description: gets the character of the tile
        * return: char
        * precondition: tile object exists
        * postcondition: returns the character of the tile
        */
        char getLetter() const;


        /*
        * description: draws the tile and the character on the tile
        * return: void
        * precondition: a tile object exists
        * postcondition: draws the tile in the window
        */
        void draw(SDL_Plotter& ) const;
};


#endif // TILE_H_INCLUDED
