#include "OutputGenerator.h"

using namespace timestamp;

OutputGenerator::OutputGenerator(const std::string& filename) : filename(filename) {
    filehandler = new FileHandler();
}

OutputGenerator::~OutputGenerator() {
    if (filehandler) {
        filehandler->closeFile();
    }
    delete filehandler;
}

bool OutputGenerator::IsFileOpen() {
    FILE* file = filehandler->getFileStream();
    return (file != nullptr);
}

OutputGenerator::OpenFileToWrite() {
    return filehandler->openFile(filename, std::ios_base::out);
}

bool OutputGenerator::WriteOutputToFile(const std::string& output) {
    if( !IsFileOpen()) {
        OpenFileToWrite();
    }

    int bytesWritten = filehandler->writeToFile(output);
    if( bytesWritten < 0) {
        std::cerr << "Error writing to file: " << filename << std::endl;
        return false;
    }
    cout << " Number of bytes written: " << bytesWritten << std::endl;
    return true;   
}