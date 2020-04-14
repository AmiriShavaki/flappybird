#ifndef SCORE_H //Just check if this class decleared before
#define SCORE_H

//Using our Graphics class
#include "Graphics.h"

const int NUMOFHURDLES = 20;

//Dimension constants
const int SCOREWIDTH = 132;
const int SCOREHEIGHT = 48;
const int SCREENWIDTH = 900;
const int SCREENHEIGHT = 504;

class Score {
private:
    int score;
    SDL_Surface* images[NUMOFHURDLES + 1];
public:
    Score(Graphics& window);
    void setScore(int score);
    void blit(Graphics& window);
};

Score::Score(Graphics& window) {
    for (int i = 0; i <= NUMOFHURDLES; i++) {
        string address = "//score//";
        if (i > 9) {
            address += i / 10 + '0';
            address += i % 10 + '0';
        } else {
            address += i + '0';
        }
        address += ".bmp";
        images[i] = window.loadImage(address);
    }
}

void Score::blit(Graphics& window) {
    window.blit(images[score], SCREENWIDTH - SCOREWIDTH, SCREENHEIGHT - SCOREHEIGHT, SCOREWIDTH, SCOREHEIGHT);
}

void Score::setScore(int score) {
    this -> score = score;
}

#endif //SCORE_H
