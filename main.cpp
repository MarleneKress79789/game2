
#include "Map.h"
#include "Player.h"
#include "Block.h"
#include "Logger.h"
#include "GameApp.h"
#include <iostream>
#include <array>

//TODO load sprites in (item?)class
//TODO make l/w h/w consitsent
//TODO make sprite class with  sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
//		 sprite.setScale(1, 1)? etc, texture
//TODO dont make everything public

#include <SDL.h>
#include <SDL_image.h>
using namespace std;

/*
 * The coordinate system used by SDL to place images on the
 * screen has 0,0 at the top-left corner of the window and SCREEN_WIDTH,SCREEN_HEIGHT
 * at the bottom-right corner. Textures are drawn back to front,
 * with each call to SDL_RenderCopy drawing the new texture on top of the current scene,
 * so we’ll want to draw our background tiles first and then draw our foreground image.
 * */


/**
* Loads an image into a texture on the rendering device
* @param file image file to load
* @param ren The renderer to load the texture onto
* @param ErrLogger The Logger you want your errors to go to
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(SDL_Renderer *ren, const std::string &file, Logger ErrLogger){
    SDL_Texture *texture = nullptr;                                         //Initialize to nullptr to avoid dangling pointer issues
    texture = IMG_LoadTexture(ren, file.c_str());                           //Load the image
    if (texture == nullptr){
        ErrLogger.logSDLError("LoadTexture");
    }
    return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height and taking a clip of the texture if desired
* If a clip is passed, the clip's width and height will be used instead of
*	the texture's
*	if a zoom is providedthe texture will be resized * zoom
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param clip The sub-section of the texture to draw (clipping/source rect)
*		default of nullptr draws the entire texture
* @param zoom Zoom multiplier for the texture size. defaults to 1
 *
 * example use of renderTexture:
        renderTexture(background, renderer, 200, 200);
        renderTexture(background, renderer, 250, 250,NULL, 2);//zoom
        SDL_Rect clip;
        clip.x = 5; //top left corner of clip
        clip.y = 5;
        clip.w = 10; //w and h of clip
        clip.h = 5;
        renderTexture(background, renderer, 300, 300, &clip);//clip,
        renderTexture(background, renderer, 350, 350, &clip, 2);//clip, zoom
 *
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
                   SDL_Rect *clip = nullptr, int zoom = 1)
{
    SDL_Rect dst;                                                           //destination rectangle
    dst.x = x;
    dst.y = y;

    if (clip != nullptr){
        dst.w = clip->w;
        dst.h = clip->h;
    }
    else {
        SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    }
    dst.w = dst.w * zoom;
    dst.h = dst.h * zoom;
    SDL_RenderCopy(ren, tex, clip, &dst);
}

int main( int argc, char* args[]) {
    Logger ErrLogger = Logger();

    GameApp ThisApp = GameApp();
    ThisApp.setup(ErrLogger);

    Map ThisMap = Map(30,20);
    ThisMap.GenerateMapContend();

    Player thisPlayer;
    thisPlayer.SetSpawn(25, 30);
    thisPlayer.xPos = thisPlayer.spawnX;
    thisPlayer.yPos = thisPlayer.spawnY;

    // array[100] NpcListe;

    Block bloeke[2];                                                    //array mit allenmöglichen blöcken, an der stelle ihres ids.


    const std::string resPath = "../Sprites/";                          //load Media, close if Error
    SDL_Texture *background = loadTexture(ThisApp.renderer, resPath + "ErdBlock.png", ErrLogger);
    SDL_Texture *player = loadTexture(ThisApp.renderer, resPath + "Player.png", ErrLogger);
    if (background == nullptr || player == nullptr){//TODO checks texture 2x :(
        SDL_DestroyTexture(background);
        SDL_DestroyTexture(player);
        ErrLogger.logSDLError("loadTExture  Error:  ");
        ThisApp.close();
        return 1;
    }


    //When we call SDL_PollEvent we get the event at the front of the
    // queue, which corresponds to the oldest event since we last polled
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){//TODO switch for e.type?
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                switch (e.key.keysym.sym){

                    case SDLK_w:
                        thisPlayer.Move(119);
                        break;
                    case SDLK_a:
                        thisPlayer.Move(97);
                        break;
                    case SDLK_s:
                        thisPlayer.Move(115);
                        break;
                    case SDLK_d:
                        thisPlayer.Move(100);
                        break;

                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }

        SDL_RenderClear(ThisApp.renderer);                                      //First clear the renderer

        //Render the scene
        float x = thisPlayer.xPos;
        float y = thisPlayer.yPos;

        int blockSizeInPixel = 15;

        int SCREEN_HEIGHT = ThisApp.GetScreenH();
        int SCREEN_WIDTH = ThisApp.GetScreenW();

        int pixeli = ((int)(y*15)) - (SCREEN_HEIGHT / 2);
        int pixelj = ((int)(x*15)) - (SCREEN_WIDTH / 2);

        for (int i = 0; i != ThisMap.height; i++) { // TODO vo anderen seiten beschränken
            pixeli = pixeli + 15;
            pixelj = (int)(x * 15) - SCREEN_WIDTH / 2;
            for (int j = 0; j != ThisMap.lenght; j++) {
                pixelj = pixelj + 15;

                if (ThisMap.MapMatrix[i][j] == 0) {
                    continue;
                }
                else if (ThisMap.MapMatrix[i][j] == 1) {
                    renderTexture(background, ThisApp.renderer, pixelj, pixeli);

                }
            }
        }

        int PlayerDestRect[] = {(SCREEN_HEIGHT / 2),(SCREEN_WIDTH / 2)};
        renderTexture(player, ThisApp.renderer,  PlayerDestRect[0], PlayerDestRect[1]);

        SDL_RenderPresent(ThisApp.renderer);                                //Update the screen
        SDL_Delay(1000);                                        //Take a quick break after all that hard work
    }

    SDL_DestroyTexture(background);
    SDL_DestroyTexture(player);
    ThisApp.close();
    return 0;
}