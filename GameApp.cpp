//
// Created by Marlene on 19/04/2020.
//

#include "GameApp.h"

GameApp::GameApp(){
    this->renderer = nullptr;
    this->window = nullptr;
    this->ErrLogger;
    this->SCREEN_WIDTH=640;
    this->SCREEN_HEIGHT=480;
}

GameApp::~GameApp(){
}

int GameApp::setup(Logger &log) {
    ErrLogger = &log;
    if (SDL_Init(SDL_INIT_VIDEO) != 0){                                     //Start up SDL, error on NULL
        ErrLogger->logSDLError("SDL_Init");
        return 1;
    }
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){      //Start up SDL_Image type png, error on NULL
        ErrLogger->logSDLError("IMG_Init");
        close();
        return 1;
    }

    window = SDL_CreateWindow("GAME!", 100, 100,                //create window, error on NULL
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        ErrLogger->logSDLError("SDL_CreateWindow Error: ");
        close();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1,                       //create rederer error on NULL
                                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        ErrLogger->logSDLError("SDL_CreateRenderer Error:  ");
        close();
        return 1;
    }
    return 0;
}

void GameApp::SetScreenW(int w) {
    SCREEN_WIDTH = w;       //TODO add if window exists -> addjust size
}

int GameApp::GetScreenW() {
    return SCREEN_WIDTH;
}

void GameApp::SetScreenH(int h) {
    SCREEN_HEIGHT = h;      //TODO add if window exists -> addjust size
}

int GameApp::GetScreenH() {
    return SCREEN_HEIGHT;
}


/**
 * Destroys given items
 * @param renderer
 * @param window
 */
void GameApp::close(){ //TODO add textureList o.Ä
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();         //TODO quits in here or time for other cleanup somewhere else?
    SDL_Quit();
}


