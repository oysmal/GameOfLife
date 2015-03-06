#include "loader.h"

Loader::Loader()
{

}

Loader::~Loader()
{

}


void Loader::loadFile(bool** array, std::fstream &file) {

}

void Loader::loadPlainTextFormat(bool** array, std::fstream &file) {

}

void Loader::loadLife105Format(bool** array, std::fstream &file) {

}

void Loader::loadLife106Format(bool** array, std::fstream &file) {

}
void Loader::loadRLEFormat(bool** array, std::fstream &file) {

}

int checkIfLife105or106(std::fstream &file) {

}

int resolveFileFormat(std::ifstream &file) {
    if(!file.is_open())
        return -1;

    std::string filename;
    try {
        std::getline(file, filename);
    } catch( std::exception e) {
        qDebug() << e.what();
    } catch(...) {
        qDebug() << "An error occured during file read\n";
    }

    if(filename == "#Life 1.05"){
            return Loader::Format::LIFE_105;
    }
    else if(filename == "#Life 1.06") {
            return Loader::Format::LIFE_106;
    }
    else {
            return Loader::Format::UNSUPPORTED_FORMAT;
    }

}
