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

    try {

        int Px, Py;

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

                    // TODO send ruleset
                    continue;
                } else if (line.substr(0,2) == "#N") {

                    // TODO send default ruleset (23/3)
                    continue;
                } else if (line.substr(0,2) == "#P") {
                    std::istringstream iss(line);
                    iss >> Px;
                    iss >> Py;

                } else {

                    // only dots and stars left

                    int linesize = line.size();

                    for (int i = 0; i < linesize; i++){
                        if(line.at(i) == "*") {
                            array[Px+i][Py] = true;
                        }
                    }
                    Py++; // in order to have it corrected for the next line, if this isn't the last.

                }

                // if line starts with #Life - jump to next
                // if line starts with #D - jump to next
                // if line starts with #R - read rule and send to GoL
                // if line starts with #N - jump to next
                // if line starts with #P - read coordinates, then go to next line
                // and read line by line and fill grid until another line starts with #P,
                // repeat until end of file
            }
        }

    } catch (std::exception e) {
        qDebug() << e.what();
    } catch (...) {
        qDebug() << "An error occured during file read\n";
    }
}

void Loader::loadLife106Format(bool** array, std::fstream &file) {


    try {
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
    } catch (std::exception e) {
        qDebug() << e.what();
    } catch (...) {
        qDebug() << "An error occured during file read\n";
    }


}
void Loader::loadRLEFormat(bool** array, std::fstream &file) {

}

int checkIfLife105or106(std::fstream &file) {
    return 0;
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
