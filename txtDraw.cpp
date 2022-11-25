/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#include "txtDraw.h"

string charToFile(char a){
    string returnVal;
        switch(a){
            case '0':
                returnVal = "0.txt";
                break;
            case '1':
                returnVal = "1.txt";
                break;
            case '2':
                returnVal = "2.txt";
                break;
            case '3':
                returnVal = "3.txt";
                break;
            case '4':
                returnVal = "4.txt";
                break;
            case '5':
                returnVal = "5.txt";
                break;
            case '6':
                returnVal = "6.txt";
                break;
            case '7':
                returnVal = "7.txt";
                break;
            case '8':
                returnVal = "8.txt";
                break;
            case '9':
                returnVal = "9.txt";
                break;
            case '+':
                returnVal = "+.txt";
                break;
            case '-':
                returnVal = "-.txt";
                break;
            case '*':
                returnVal = "+^.txt";
                break;
            case '/':
                returnVal = "-^.txt";
                break;
            case '=':
                returnVal = "=.txt";
                break;
            default:
                returnVal = "ERROR";
      }
      return returnVal;
}

void drawTxt (char key, SDL_Plotter& g, tile box){
   int textFileRows = 50;
   int textFileCols = 50;
   int spaceFromLeftEdge = 9;
   int spaceFromTopEdge = 7;


   string fileName = charToFile(key);
   ifstream file;
   file.open(fileName);
   int toDraw;
   for(int r = 0; r < textFileRows; r++){
      for(int c = 0; c < textFileCols ; c++){
         file >> toDraw;
         if(toDraw == 1) {
             g.plotPixel(spaceFromLeftEdge + box.getLocation().getX() + c,
                         spaceFromTopEdge + box.getLocation().getY() + r,
                         255,255,255);
         }
      }
   }
   file.close();
}
void whiteOutBottom (SDL_Plotter& g){
    for(int y = 580; y < 799; y++){
        for(int x = 290; x < 1200; x++){
            g.plotPixel(x,y,255,255,255);
        }

    }
}

void whiteOutTop (SDL_Plotter& g){
    for(int y = 1; y < 140; y++){
        for(int x = 300; x < 1000; x++){
            g.plotPixel(x,y,255,255,255);
        }

    }
}
void drawObject(SDL_Plotter& g, txtBox name, color_t colText) {
  ifstream file;
  file.open(name.textFileName);
  int toDraw;
  for(int r = 0; r < name.height; r++){
     for(int c = 0; c < name.width ; c++){
        file >> toDraw;
        if(toDraw == 1) {
            g.plotPixel(name.location.getX() + c,
                        name.location.getY() + r,
                        colText.R,colText.G,colText.B);
        }
     }

  }
  file.close();
}
