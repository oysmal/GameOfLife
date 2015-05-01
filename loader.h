#ifndef LOADER_H
#define LOADER_H

#include <fstream>
#include <istream>
#include <iostream>
#include <sstream>
#include <QDebug>
#include "grid.h"
#include <regex>

class Loader
{
public:
    Loader();
    ~Loader();

    enum Format { PLAIN_TEXT, LIFE_105, LIFE_106, RLE, UNSUPPORTED_FORMAT, FILE_NOT_OPEN};

    static void loadFile(std::string filepath);
    static void loadPlainTextFormat(std::string filepath);
    static void loadLife105Format(std::string filepath);
    static void loadLife106Format(std::string filepath);
    static void loadRLEFormat(std::string filepath);
};

#endif // LOADER_H
