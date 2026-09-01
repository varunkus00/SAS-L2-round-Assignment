#include <iostream>
#include "FileHandler.h"

namespace timestamp {

    class FileHandler;
    class InputFileReader {

      public:
        InputFileReader(const std::string& filename);
        ~InputFileReader();

        bool ReadFromFile();
        FILE* OpenFileToRead();
        bool isFileOpen();
        char** getFileContent() {
            return fileContent;
        }

      private:
        FileHandler* filehandler;
        std::string filename;
        char** fileContent;
        //std::string output;
    };    

}    