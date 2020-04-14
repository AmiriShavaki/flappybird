//Using our Graphics, Bird, Pipe, Score and Hurdle classes and standard IO and SDL and time
#include <iostream>
#include "Graphics.h"
#include "Bird.h"
#include <SDL.h>
#include "Score.h"
#include "Hurdle.h"
#include <ctime>

const int GROUNDY = 446;

//Constants of hurdles
const int HURDLESDISTANCE = 300;
const int FIRSTHURDLEX = 900;
const int TIMESPEED = 10;

void showHurdles(Graphics& window, SDL_Surface* topPipe, SDL_Surface* bottomPipe, Hurdle* hurdles) {
    for (int i = 0; i < NUMOFHURDLES; i++) {
        hurdles[i].blit(window, topPipe, bottomPipe);
    }
}

void setHurdlesX(int t, Hurdle* hurdles) { //Set x coordinates of hurdles
    for (int i = 0; i < NUMOFHURDLES; i++) {
        hurdles[i].setX(i * HURDLESDISTANCE + FIRSTHURDLEX - t);
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); //Set random seed

    Graphics window(SCREENWIDTH, SCREENHEIGHT); //Start up SDL and create window

    //Load background images
    SDL_Surface* bg = window.loadImage("background.bmp");
    SDL_Surface* gr = window.loadImage("ground.bmp");
    SDL_Surface* bgGameOver = window.loadImage("endGame//gameOver.bmp");
    SDL_Surface* bgYouWon = window.loadImage("endGame//youWon.bmp");

    //Load pipes image
    SDL_Surface* topPipe = window.loadImage("topPipe.bmp");
    SDL_Surface* bottomPipe = window.loadImage("bottomPipe.bmp");

    Bird bird(window); //Create bird object

    Hurdle hurdles[NUMOFHURDLES]; //Create array of hurdle objects

    int t = 0; //Time variable

    Score score(window); //Create score object

    while (!window.isClosed()) {
        if (window.getEvents()) { //Check space pressed and change speed if it was necessary
            bird.jump();
        }

        if ((bird += VG) + BIRDHEIGHT >= GROUNDY) {
            //Hit the ground
            window.blit(bgGameOver, 0, 0, SCREENWIDTH, SCREENHEIGHT);
            window.update();
            break;
        }

        window.blit(bg, 0, 0, SCREENWIDTH, SCREENHEIGHT); //Show background image in order to clear the screen

        setHurdlesX(t, hurdles);

        showHurdles(window, topPipe, bottomPipe, hurdles);

        window.blit(gr, 0, GROUNDY, SCREENWIDTH, SCREENHEIGHT); //Show ground image in order to hide junktions of pipes

        bird.blit(window);

        int curScore = bird.updateScore(hurdles, score, window); //Current score

        if (curScore == -1) { //Collision check
            window.blit(bgGameOver, 0, 0, SCREENWIDTH, SCREENHEIGHT);
            window.update();
            break;
        } else if (curScore == 20) { //You Won!
            window.blit(bgYouWon, 0, 0, SCREENWIDTH, SCREENHEIGHT);
            window.update();
            break;
        }

        score.blit(window);

        window.update();
        window.delay(50); //50 miliseconds

        t += TIMESPEED; //Increasing time variable
    }
    window.delay(10000); //10 seconds
    window.endGame();
	return 0;
}
