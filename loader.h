#ifndef LOADER_H
#define LOADER_H

#include <fstream>

class Loader
{
public:
    Loader();
    ~Loader();

    enum Format { PLAIN_TEXT, LIFE_105, LIFE_106, RLE, UNSUPPORTED_FORMAT};

    static void loadFile(bool** array, std::fstream &file);
    static void loadPlainTextFormat(bool** array, std::fstream &file);
    static void loadLife105Format(bool** array, std::fstream &file);
    static void loadLife106Format(bool** array, std::fstream &file);
    static void loadRLEFormat(bool** array, std::fstream &file);

    int checkIfLife105or106(std::fstream &file);
    int resolveFileFormat(std::fstream &file);
};

#endif // LOADER_H
