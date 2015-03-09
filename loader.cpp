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

    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {

            if(line.substr(0,2) == "#D") {
                continue;
            } else if (line.substr(0,2) == "#R") {
                std::string start;
                int rule1, rule2;
                char divider;

                std::istringstream iss(line);
                iss >> start;
                iss >> rule1;
                iss >> divider;
                iss >> rule2;

            }

            // if line starts with #Life - jump to next
            // if line starts with #D - jump to next
            // if line starts with #R - read rule and send to GoL
            // if line starts with #N - jump to next
            // if line starts with #P - read coordinates, then go to next line
            // and read line by line and fill grid until another line starts with #P,
            // repeat until end of file

            std::string start;
            int x, y;
            std::istringstream iss(line);
        }
        file.close();
    }


}

void Loader::loadLife106Format(bool** array, std::fstream &file) {

    std::string line;
    if(file.is_open()) {
        while (getline(file, line)) {
            // if line starts with #Life - jump to next
            // else read coordinates, fill grid with living cells until end of file

            // find center of array

            int x, y;
            std::istringstream iss(line);
            iss >> x;
            iss >> y;
            array[x][y] = true;
        }
    }


}
void Loader::loadRLEFormat(bool** array, std::fstream &file) {

}

int checkIfLife105or106(std::fstream &file) {

}

Loader::Format resolveFileFormat(std::ifstream &file) {
    if(!file.is_open())
        return Loader::Format::FILE_NOT_OPEN;

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
