#include <iostream>
#include "FileHandler.h"

namespace timestamp {

    class FileHandler;
    class OutputGenerator {

      public:
        OutputGenerator();
        ~OutputGenerator();

        void WriteOutputToFile(const std::string& output, const std::string& filename);

      private:
        FileHandler* filehandler;
        std::string output;
    };    

}    