#include <iostream>

//TODO load sprites in class

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << SDL_GetError() << std::endl;
}

/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(SDL_Renderer *ren, const std::string &file){
    //Initialize to nullptr to avoid dangling pointer issues
    SDL_Texture *texture = nullptr;
    //Load the image
    texture = IMG_LoadTexture(ren, file.c_str());

    if (texture == nullptr){
        logSDLError(std::cout, "LoadTexture");
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
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
                   SDL_Rect *clip = nullptr, int zoom = 1)
{
    SDL_Rect dst; //destination rectangle
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

int main( int argc, char* args[] ) {
    //Start up SDL error on NULL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        logSDLError(std::cout, "SDL_Init");
        return 1;
    }
    //Start up SDL_Image type png error on NULL
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
        logSDLError(std::cout, "IMG_Init");
        SDL_Quit();
        return 1;
    }

    //create window error on NULL
    SDL_Window *window = SDL_CreateWindow("GAME!", 100, 100, SCREEN_WIDTH,
                                       SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        logSDLError(std::cout, "SDL_CreateWindow Error: ");
        SDL_Quit();
        return 1;
    }
    //create rederer error on NULL
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        SDL_DestroyWindow(window);
        logSDLError(std::cout, "SDL_CreateRenderer Error:  ");
        SDL_Quit();
        return 1;
    }

    //load Media, close if Error

    const std::string resPath = "../Sprites/";
    SDL_Texture *background = loadTexture(renderer, resPath + "ErdBlock.png");
    SDL_Texture *image = loadTexture(renderer, resPath + "Player.png");
    if (background == nullptr || image == nullptr){//TODO checks texture 2x :(
        SDL_DestroyTexture(background);
        SDL_DestroyTexture(image);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        logSDLError(std::cout, "loadTExture  Error:  ");
        SDL_Quit();
        return 1;
    }


    //When we call SDL_PollEvent we get the event at the front of the
    // queue, which corresponds to the oldest event since we last polled
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                switch (e.key.keysym.sym){
                    case SDLK_1:
                        useClip = 0;
                        break;
                    case SDLK_2:
                        useClip = 1;
                        break;
                    case SDLK_3:
                        useClip = 2;
                        break;
                    case SDLK_4:
                        useClip = 3;
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
        /*
         * The coordinate system used by SDL to place images on the
         * screen has 0,0 at the top-left corner of the window and SCREEN_WIDTH,SCREEN_HEIGHT
         * at the bottom-right corner. Textures are drawn back to front,
         * with each call to SDL_RenderCopy drawing the new texture on top of the current scene,
         * so we’ll want to draw our background tiles first and then draw our foreground image.
         * */
        //Render the scene
        //First clear the renderer
        SDL_RenderClear(renderer);

        //ceep as exaple use of render Texture
        renderTexture(background, renderer, 200, 200);
        renderTexture(background, renderer, 250, 250,NULL, 2);//zoom
        SDL_Rect clip;
        clip.x = 5; //top left corner of clip
        clip.y = 5;
        clip.w = 10; //w and h of clip
        clip.h = 5;
        renderTexture(background, renderer, 300, 300, &clip);//clip,
        renderTexture(background, renderer, 350, 350, &clip, 2);//clip, zoom
        //Update the screen
        SDL_RenderPresent(renderer);
        //Take a quick break after all that hard work
        SDL_Delay(1000);
    }


    SDL_DestroyTexture(background);
    SDL_DestroyTexture(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}