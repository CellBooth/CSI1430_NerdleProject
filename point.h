/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class point{
    private:
        int x, y;
    public:
        point(int = 0, int = 0);
        //************************************************************
        // description: sets the x value                             *
        // return: void                                              *
        // precondition: valid int given as x and valid x dimension  *
        //    window given (prevents out of range errors)            *
        // postcondition: function sets the x value of the point     *
        //************************************************************
        void setX(int = 0, int = 0);
        //************************************************************
        // description: sets the y value                             *
        // return: void                                              *
        // precondition: valid int given as y                        *
        // postcondition: function sets the y value of the point     *
        //************************************************************
        void setY(int = 0);
        //************************************************************
        // description: gets the x value                             *
        // return: int                                               *
        // precondition: x has a value                               *
        // postcondition: function gets the x value of the point     *
        //************************************************************
        int getX() const;
        //************************************************************
        // description: gets the y value                             *
        // return: int                                               *
        // precondition: y has a value                               *
        // postcondition: function gets the y value of the point     *
        //************************************************************
        int getY() const;


};


#endif // POINT_H_INCLUDED
