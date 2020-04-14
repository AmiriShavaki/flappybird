#ifndef GRAPHICS_H //Just check if this class decleared before
#define GRAPHICS_H

//Using SDL and string
#include <SDL.h>
#include <string>
using namespace std;

class Graphics {
private:
    SDL_Window* window; //The window we'll be rendering to
    SDL_Surface* screenSurface; //The surface contained by the window
    SDL_Event event; //Our event reader
public:
    Graphics(const int width, const int height);
    void blit(SDL_Surface* image, const int x, const int y, const int width, const int height);
    void update();
    void delay(int amount);
    void endGame(); //Close
    const bool getEvents();
    const bool isClosed();
    SDL_Surface* loadImage(string fileName);
};

SDL_Surface* Graphics::loadImage(string fileName) {
    string address = "pictures//"; address += fileName; //Make address string in order to load the image

    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    //Load the image and make its surface
    SDL_Surface* image = SDL_LoadBMP(address.data());
    image = SDL_ConvertSurface(image, screenSurface -> format, 0);

    //Return pointer to loaded image
    return image;
}

const bool Graphics::isClosed() {
    return window == NULL;
}

void Graphics::endGame() {
    SDL_DestroyWindow(window);
    window = NULL;
}

const bool Graphics::getEvents() {
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                endGame();
                return false;
            break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE) {
                    return true;
                }
            break;
        }
    }
    return false;
}

void Graphics::delay(int amount) {
    SDL_Delay(amount); //Wait some seconds
}

void Graphics::update() {
    SDL_UpdateWindowSurface(window); //Update the surface
}

void Graphics::blit(SDL_Surface* image, const int x, const int y, const int width, const int height) {
    //Make position object
    SDL_Rect position;
    position.x = x;
    position.y = y;
    position.h = height;
    position.w = width;

    SDL_BlitScaled(image, NULL, screenSurface, &position); //Apply the image
}

Graphics::Graphics(const int width, const int height) {
    //Create window
    window = SDL_CreateWindow("flappybird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);
}

#endif //GRAPHICS_H
