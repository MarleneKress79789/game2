//
// Created by Marlene on 19/04/2020.
//

#include <SDL.h>
#include "Logger.h"
#include <SDL_image.h>

#ifndef GAME_APP_H
#define GAME_APP_H


class GameApp {
public:
    GameApp();
    ~GameApp();

    /**
     * sets up the app with window, renderer, and init for sdl
     * @param ErrLogger the Logger to logg errors with
     * @return returns 0 on succes, 1 otherwise
     */
    int setup(Logger &ErrLogger);

    /**
     * destroys the apps window, renderer, and closes sdl
     */
    void close();

    void SetScreenW(int w);      //TODO as vector?
    int GetScreenW();
    void SetScreenH(int h);
    int GetScreenH();

    SDL_Window *window;
    SDL_Renderer *renderer;
    Logger *ErrLogger;

private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
};


#endif //GAME_APP_H
