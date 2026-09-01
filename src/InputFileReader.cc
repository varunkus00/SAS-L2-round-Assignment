#include "OutputGenerator.h"

using namespace timestamp;

InputFileReader::InputFileReader(const std::string& filename) : filename(filename) {
    filehandler = new FileHandler();
}

InputFileReader::~InputFileReader() {
    if (filehandler) {
        filehandler->closeFile();
    }
    delete filehandler;
}

bool InputFileReader::IsFileOpen() {
    FILE* file = filehandler->getFileStream();
    return (file != nullptr);
}

InputFileReader::OpenFileToRead() {
    return filehandler->openFile(filename, std::ios_base::in);
}

bool InputFileReader::ReadFromFile() {
    if( !IsFileOpen()) {
        OpenFileToRead();
    }
    // Implementation for reading from file

    filehandler->readFile();
    fileContent = filehandler->getFileContent();

    return true;

}