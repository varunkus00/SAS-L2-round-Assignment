#include <iostream>
#include "FileHandler.h"

namespace timestamp {

    class FileHandler;
    class OutputGenerator {

      public:
        OutputGenerator(const std::string& filename);
        ~OutputGenerator();

        bool WriteOutputToFile(const std::string& output);
        FILE* OpenFileToWrite();
        bool isFileOpen();

      private:
        FileHandler* filehandler;
        std::string filename;
        //std::string output;
    };    

}    