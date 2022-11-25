/*
* Author: Cole Flenniken, Daechan (Martin) Lee, Jonathan Chabot, Xavier Dawes, Joanna Oh
* Assignment Title: Nerdle: Group Project
* Assignment Description: A working nerdle game
* Due Date: 3/18/2022
* Date Created: 5/5/2022
* Date Last Modified: 5/5/2022
 */
#include <iostream>
#include "color.h"
#include "constants.h"
#include "SDL_Plotter.h"
#include "tile.h"
#include "DoesItCompute.h"
#include "Postguesscolorset.h"
#include "txtDraw.h"
#include "txtBox.h"

using namespace std;
//for window size

int main(int argv, char** args){ //Depending on the device WinMain may need to become main

    int BOX_COL = 16;
    int NUM_COL = (TILE_GAP + TILE_WIDTH) * BOX_COL + TILE_GAP; //THIS WAS 500
    bool keepPlaying = true;
    //These declare the objects that display lines of text (more than one character
    txtBox coledle("coledle.txt",PURPLE,99,335,NUM_COL / 2 - 335 / 2, NUM_COL,TILE_GAP * 3);
    txtBox openScreen( "openingscreen.txt" , PURPLE, 266, 325,NUM_COL / 2 - 325 / 2, NUM_COL,NUM_ROW / 3);
    txtBox winScreen("winscreen.txt", BLACK, 135,311,475,NUM_COL, 340);
    txtBox loseScreen("losescreen.txt", BLACK, 135,312,475,NUM_COL, 340);
    txtBox RulesP1("RulesL.txt",BLACK,202, 350, 300, NUM_COL, 585);
    txtBox RulesP2("RulesR.txt",BLACK,201, 353, 650, NUM_COL, 585);
    txtBox controlsL("controlsL.txt",BLACK,202,350,300,NUM_COL, 585);
    txtBox controlsR("controlsR.txt",BLACK,201,353,650,NUM_COL, 585);
    txtBox creditsL("creditsL.txt",BLACK,202,350,300,NUM_COL, 585);
    txtBox creditsR("creditsR.txt",BLACK,201,353,650,NUM_COL, 585);
    txtBox legend("Legend.txt",BLACK,201,230,50,NUM_COL, 585);
    txtBox errorL("errorL.txt",BLACK,74,300,320,NUM_COL, 30);
    txtBox errorR("errorR.txt",BLACK,73,330,620,NUM_COL, 30);


    SDL_Plotter g(NUM_ROW,NUM_COL);
    while(!g.getQuit() && keepPlaying == true){
        //Draws screen white (needed for replay)
        for(int x = 0; x < 1871; x++){
            for(int y = 0; y < 799; y++){
                g.plotPixel(x,y,255,255,255);
            }
        }
        drawObject(g,openScreen, PURPLE);
        g.update();
        int difficulty = 8;
        char diffL;
        bool difficultySet = false;
        //The difficulty determines the length of the
        //equation the user will guess
        while( difficultySet == false){
            if(g.kbhit()){
                diffL = g.getKey();
                cout << diffL;
                if( diffL == 'A'){
                    difficulty = 8;
                    difficultySet = true;
                }
                else if(diffL == 'B'){
                    difficulty = 10;
                    difficultySet = true;
                }
                else if(diffL == 'C'){
                    difficulty = 12;
                    difficultySet = true;
                }
                else if(diffL == 'D'){
                    difficulty = 14;
                    difficultySet = true;
                }
                else if(diffL == 'E'){
                    difficulty = 16;
                    difficultySet = true;
                }
            }
        }

        for(int x = 0; x < NUM_COL; x++){
            for(int y = 0; y < NUM_ROW; y++){
                g.plotPixel(x,y,255,255,255);
            }
        }
        g.update();
        tile mainBoard;
        tile box[BOX_ROW][difficulty];
        point mb_TileLocation; //the top left location
        string correctEq = EquationGenerator(difficulty);
        //To hide answer, comment out this line. Else, the answer will be printed to the screen
        cout << ": " << correctEq;
        mainBoard.setColor("CGREY");
        bool runGame = true;
        bool startRow = true;
        int col = 0, row = 0;
        string userEq = "";
        bool gameWon = false;
        char kbVal;
        //fills the box array with tile object and draws boxes to the SDL Plotter
        for(int c = 0; c < difficulty; c++) {
            mb_TileLocation.setX((TILE_WIDTH + TILE_GAP)*c + TILE_LEFTSPACE + ((16- difficulty) * (TILE_WIDTH + TILE_GAP) / 2), NUM_COL);
            for(int r = 0; r < BOX_ROW; r++) {
                mb_TileLocation.setY((TILE_HEIGHT + TILE_GAP)*r + TILE_UPPERSPACE);
                mainBoard.setLocation(mb_TileLocation);
                mainBoard.setHeight(TILE_HEIGHT);
                mainBoard.setWidth(TILE_WIDTH);
                box[r][c] = mainBoard;
                box[r][c].draw(g);
            }
        }
        drawObject(g, coledle, PURPLE);
        drawObject(g,legend,BLACK);
        g.update();

        while(runGame == true && !g.getQuit()){
            char key;
            //the next if statement houses the controls where while the user is playing the game
            //this includes the keys to type, backspace, enter, and display the rules, controls
            //and credits dialog boxes
            if(g.kbhit()){
                kbVal = g.getKey();
                whiteOutTop(g);
                drawObject(g,coledle, PURPLE);
                //writes characters to boxes
                if(charToFile(kbVal) != "ERROR" && (col % difficulty != 0 || startRow == true )){
                    startRow = false;
                    key = kbVal;
                    drawTxt (key,g, box[row][col % difficulty]);
                    g.update();
                    box[row][col % difficulty].setLetter(key);
                    userEq = userEq + key;
                    col++;
                    if(row >= BOX_ROW){
                        runGame = false;
                    }
                }
                //backspace
                else if(kbVal == '\b' && startRow == false){
                    col--;
                    if(col % difficulty == 0){
                        startRow = true;
                    }
                    userEq.pop_back();
                    box[row][col % difficulty].draw(g);
                    g.update();
                }
                //enter submits a full guess
                else if(kbVal == SDL_SCANCODE_RETURN){
                    //cout << "enter";
                    if(col % difficulty == 0 && startRow == false){
                        if(DoesItCompute(userEq) == true){
                            vector<string> colorSet = PostguessColorSet(correctEq, userEq);
                            for(int cp = 0 ; cp < difficulty ; cp++){
                                box[row][cp].setColor(colorSet.at(cp));
                                box[row][cp].draw(g);
                                drawTxt (box[row][cp].getLetter(),g, box[row][cp]);
                                startRow = true;
                            }
                            if(correctEq == userEq){
                                gameWon = true;
                                runGame = false;
                            }
                            else if(row == 5){
                                runGame = false;
                            }
                            g.update();
                            row++;
                            userEq = "";
                        }
                        else{
                            //Message for if the user equation does not compute
                            whiteOutTop(g);
                            drawObject(g,errorL,BLACK);
                            drawObject(g,errorR,BLACK);

                        }
                    }
                }
                //displays rules at bottom of screen
                else if(kbVal == 'D'){
                    whiteOutBottom(g);
                    drawObject(g,RulesP1, BLACK);
                    drawObject(g,RulesP2, BLACK);

                }
                //displays controls at bottom of screens
                else if(kbVal == 'F'){
                    whiteOutBottom(g);
                    drawObject(g,controlsL,BLACK);
                    drawObject(g,controlsR,BLACK);

                }
                //displays credits to screen
                else if(kbVal == 'C'){
                    whiteOutBottom(g);
                    drawObject(g,creditsL,BLACK);
                    drawObject(g,creditsR,BLACK);

                }
                g.update();
            }
        }
        if(!g.getQuit()){
            //prints outline of win/lose screen
            for (int x = NUM_COL/2 - 155 ; x< NUM_COL /2 + 155; x++){
                for (int y = 295; y < NUM_ROW - 295; y++){
                    g.plotPixel(x,y,0,0,0);
                }
            }
            int re = 0,ge = 0,be = 0;
            if(gameWon == true){
                ge = 255;
            }
            else{
                re = 255;
            }
            //prints green/red box depending on if game was one or not
            for (int x = NUM_COL / 2 - 150 ; x< NUM_COL/2 + 150 ; x++){
                for (int y = 300; y < NUM_ROW - 300; y++){
                    g.plotPixel(x,y,re,ge,be);
                }
            }
            //prints dialog for winning and losing
            if(gameWon == true){
                drawObject(g, winScreen, CWHITE);

            }
            else{
                drawObject(g, loseScreen, CWHITE);
            }
            g.update();
        }
        char tt = '\n';
        while(tt == '\n'){
            if(g.kbhit()){
                //enables replay of game
                tt = g.getKey();
                if(tt != 'R'){
                    keepPlaying = false;
                }
                else{
                    for(int x = 0; x < 1871; x++){
                        for(int y = 0; y< 799; y++){
                            g.plotPixel(x,y,255,255,255);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
