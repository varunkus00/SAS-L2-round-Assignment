#include "FileHandler.h"

using namespace timestamp;

FileHandler::FileHandler() {
    // Constructor implementation
    file = nullptr;
    offset = 0;
    currIdx = 0;
    for (int i = 0; i < 10; i++) {
        fileContent[i] = nullptr;
    }

    memset(buffer, 0, sizeof(buffer));

}

FileHandler::~FileHandler() {
    // Destructor implementation
    if (file) {
        fclose(file);
    }

    memset(buffer, 0, sizeof(buffer));
    // Clean up dynamically allocated memory
    for(int i = 0; i < 10; i++) {
        delete[] fileContent[i];
    }
    //delete file;
    
}

FILE* FileHandler::getFileStream() {
    return file;
}

FILE* FileHandler::openFile(const std::string& filename, std::ios_base::openmode mode) {
    
    if( !file ) {
        file = fopen(filename.c_str(), mode == std::ios_base::in ? "r" : "w+");
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return nullptr;
        }
    }
    return file;
}   

void FileHandler::closeFile() {
    if (file) {
        fclose(file);
    }
    
}

void FileHandler::writeToFile(const std::string& output) {
    if (file) {
        fwrite(output.c_str(), sizeof(char), output.size(), file);
    } else {
        std::cerr << "File is not open for writing." << std::endl;
    }
}

void FileHandler::readFile() {

    if( !file) {
        return;
    }

    std::cout << " Going to read file content" << std::endl;
    int bytesRead = 0;
    while ( (bytesRead = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file)) > 0) {
        //fread(buffer, sizeof(buffer), MAX_BUFFER_SIZE, file);
        //offset += file.gcount();
        std::cout << " Reading file content linennumber 74" << std::endl;
        int i = 0;
        while( i < MAX_BUFFER_SIZE) {
            int pos = 0, stPos = i;
            while( buffer[i] != '\n' && buffer[i] != '\0' && i < MAX_BUFFER_SIZE) {
                pos++;
                i++;
            }
            int len = pos - stPos;
            if( len > 0 ) {
                fileContent[currIdx] = new char[len + 1];
                strncpy(fileContent[currIdx], buffer + stPos, len);
                fileContent[currIdx][len] = '\0';
                currIdx++;
                std::cout << " Read line: " << fileContent[currIdx - 1] << std::endl;
            }
            i++;
        }
        // Process the read data as needed
    }
}            