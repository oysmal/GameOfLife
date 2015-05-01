//#include "filemanager.h"

//FileManager::FileManager()
//{
//    this->array2d = nullptr;
//    this->loader = Loader();
//}

//FileManager::~FileManager()
//{
//    close_file();
//    delete this->array2d;
//}


//void FileManager::open_file(std::string filePath) {
//    try {
//        this->file.open(filePath.c_str(), std::fstream::in);
//    } catch (...) {
//        std::cout << "Error occured during file open operation.\n";
//    }
//}


//void FileManager::close_file() {
//    if(this->file.is_open()) {
//        this->file.close();
//    }
//}

//void FileManager::read_file(bool **array) {
//    Loader::loadFile(this->array2d, this->file);
//    array = array2d;
//}
