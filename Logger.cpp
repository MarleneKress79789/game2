//
// Created by Marlene on 19/04/2020.
//

#include "Logger.h"
#include <iostream>

#include <SDL.h>

Logger::Logger(){
    this-> mode = "cout";
}

Logger::Logger(std::string mode){
    this-> mode = mode;
}

Logger::~Logger(){
}

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void Logger::logSDLError(const std::string &msg){
    if (mode =="cout"){
        std::cout << msg << " error: " << SDL_GetError() << std::endl;
    }
    else{
        std::cout << " error: Logger mode " << mode <<" not defined" << SDL_GetError() << std::endl;
    }
}