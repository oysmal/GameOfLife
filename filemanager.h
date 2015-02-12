#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "loader.h"
#include <fstream>
#include <string>
#include <iostream>

class FileManager
{
public:
    FileManager();
    ~FileManager();

    void open_file(std::string filePath);
    void read_file(bool** array);
    void close_file();
    Format resolveFileFormat();

private:
    Loader loader;
    bool** array2d;
    std::fstream file;
};

#endif // FILEMANAGER_H
