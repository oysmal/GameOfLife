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

int resolveFileFormat(std::fstream &file) {
    if(!file.is_open())
        return -1;

    std::string filename;
    try {
        filename = file.getline();
    } catch( std::exception e) {
        qDebug() << e.what();
    } catch(...) {
        qDebug() << "An error occured during file read\n";
    }

    switch(filename) {
        case "#Life 1.05":
            return Loader::Format::LIFE_105;
        case "#Life 1.06":
            return Loader::Format::LIFE_106;
        default:
            return Loader::Format::UNSUPPORTED_FORMAT;
    }

}
