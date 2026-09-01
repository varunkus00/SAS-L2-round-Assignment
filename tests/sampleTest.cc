#include <iostream>
#include "sample.h"
#include "TimeStampWrapperClass.h"

using namespace timestamp;

int main() {
    //print_message();

    TimeStampWrapperClass timestampWrapper;
    //timestamp::TimeValidator* timeValidator = timestampWrapper.getTimeValidator();
    timestamp::FileHandler* fileHandler = timestampWrapper.getFileHandler();
    
    FILE* fp = fileHandler->openFile("C:\\Users\\shriv\\SAS\\SAS-L2-round-Assignment\\InputTimeStamps", std::ios_base::in);
    if( !fp) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    } else {
        
        std::cout << "Input file opened successfully." << std::endl;
    }

    fileHandler->readFile();

    char **fileContent = fileHandler->getFileContent();
    while( fileContent != nullptr) {
        std::cout << *fileContent << std::endl;
        fileContent++;
    }

    //fileHandler->openFile("C:\\Users\\shriv\\SAS\\SAS-L2-round-Assignment\\OutputTimeStamps.txt", std::ios_base::out);

    return 0;
}