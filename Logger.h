//
// Created by Marlene on 19/04/2020.
//

#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#include <iostream>


class Logger {
public:

    Logger();
    Logger(std::string mode);
    ~Logger();

    /**
     * Loggs a message + error
     * @param msg the message to be logged befor the error
     */
    void logSDLError(const std::string &msg);

    std::string mode; //Null(cout), TODO FIle etc
};


#endif //GAME_LOGGER_H
