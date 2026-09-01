#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <stdio.h>

#define MAX_BUFFER_SIZE 1024

namespace timestamp {

    class FileHandler {

      public:
        FileHandler();
        ~FileHandler();

        FILE* getFileStream();
        FILE* openFile(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        void closeFile();
        void writeToFile(const std::string& output);
        void readFile();
        char** getFileContent() {
            return fileContent;
        }
      private:
        FILE* file;
        char buffer[MAX_BUFFER_SIZE];
        int offset;
        char* fileContent[10];
        int currIdx;
    };

}

#endif // FILE_HANDLER_H