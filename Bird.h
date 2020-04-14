#ifndef BIRD_H //Just check if this class decleared before
#define BIRD_H

//Using min/max from algorithm lib and our Graphics, Hurdle and Score classes
#include <algorithm>
#include "Graphics.h"
#include "Hurdle.h"
#include "Score.h"

//Bird dimension constants
const int BIRDWIDTH = 50;
const int BIRDHEIGHT = 35;

//Bird initial position
const int INITX = 200;
const int INITY = 150;

//Physics constants
const int VG = 10;
const int VU = -(VG + VG / 4);

class Bird {
private:
    int x; //X coordinate
    int y; //Y coordinate
    int s; //Speed
    int score;
    SDL_Surface* image;
public:
    Bird(Graphics &window);
    void jump();
    const int operator+=(const int g);
    void blit(Graphics& window);
    int updateScore(Hurdle* hurdles, Score& score, Graphics& window);
};

int Bird::updateScore(Hurdle* hurdles, Score& score, Graphics& window) {
    this -> score = 0;
    for (int i = 0; i < NUMOFHURDLES; i++) {
            if (hurdles[i].intersect(x, y, x + BIRDWIDTH, y + BIRDHEIGHT)) { //Collision check for game over case
                return -1;
            }
            if (hurdles[i].getX2() < x) {
                (this -> score)++;
            }
    }
    score.setScore(this -> score);
    return this -> score;
}

void Bird::blit(Graphics& window) {
    window.blit(image, x, y, BIRDWIDTH, BIRDHEIGHT);
}

const int Bird::operator+=(const int g) {
    s = min(s + 1, g);
    y += s;
    return y;
}

void Bird::jump() {
    s = VU;
}

Bird::Bird(Graphics& window) {
    x = INITX;
    y = INITY;
    s = VG;
    score = 0;
    image = window.loadImage("bird.bmp");
}

#endif //BIRD_H
