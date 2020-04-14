#ifndef HURDLE_H //Just check if this class decleared before
#define HURDLE_H

//Using c++ random number generator and SDL
#include <cstdlib>
#include <ctime>
#include <SDL.h>

//Constants
const int MINH = 100;
const int DOMAINH = 100;
const int MINY = -250;
const int PIPEHEIGHT = 300;
const int PIPEWIDTH = 77;

class Hurdle {
private:
    int x;
    int y;
    int h;
public:
    Hurdle();
    void blit(Graphics& window, SDL_Surface* topPipe, SDL_Surface* bottomPipe);
    void setX(int x);
    const bool intersect(int x1, int y1, int x2, int y2) const;
    const int getX2() const;
};

const int Hurdle::getX2() const {
    return x + PIPEWIDTH;
}

const bool Hurdle::intersect(int x1, int y1, int x2, int y2) const {
    int rect1X1 = x, rect1Y1 = y, rect1X2 = x + PIPEWIDTH, rect1Y2 = y + PIPEHEIGHT; //Top pipe dimensions
    int rect2X1 = x, rect2Y1 = rect1Y2 + h, rect2X2 = x + PIPEWIDTH, rect2Y2 = rect2Y1 + PIPEHEIGHT; //Bottom pipe dimensions

    bool rect1Intersect = !(rect1X1 > x2 || rect1X2 < x1 || rect1Y1 > y2 || rect1Y2 < y1);
    bool rect2Intersect = !(rect2X1 > x2 || rect2X2 < x1 || rect2Y1 > y2 || rect2Y2 < y1);
    return rect1Intersect || rect2Intersect;
}

void Hurdle::setX(int x) {
    this -> x = x;
}

void Hurdle::blit(Graphics& window, SDL_Surface* topPipe, SDL_Surface* bottomPipe) {
    window.blit(topPipe, x, y, PIPEWIDTH, PIPEHEIGHT);
    window.blit(bottomPipe, x, y + h + PIPEHEIGHT, PIPEWIDTH, PIPEHEIGHT);
}

Hurdle::Hurdle() {
    h = rand() % DOMAINH + MINH;
    y = rand() % DOMAINH + MINY;
}

#endif //HURDLE_H
