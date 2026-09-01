#include "TimeStampWrapperClass.h"

using namespace timestamp;

TimeStampWrapperClass::TimeStampWrapperClass(const std::string& inputFileName, const std::string& outputFileName) {
    timeValidator = new TimeValidator();
    inputFileReader = new InputFileReader(inputFileName);
    outputGenerator = new OutputGenerator(outputFileName);
    uniqueValueChecker = new UniqueValueChecker();
}

TimeStampWrapperClass::~TimeStampWrapperClass() {
    delete timeValidator;
    delete inputFileReader;
    delete outputGenerator;
    delete uniqueValueChecker;
}

TimeValidator* TimeStampWrapperClass::getTimeValidator() {
    return timeValidator;
}

InputFileReader* TimeStampWrapperClass::getInputFileReader() {
    return inputFileReader;
}

OutputGenerator* TimeStampWrapperClass::getOutputGenerator() {
    return outputGenerator;
}

void TimeStampWrapperClass::run() {

    inputFileReader->ReadFromFile();
    char** fileContent = inputFileReader->getFileContent();
    while (fileContent != nullptr && *fileContent != nullptr) {
        std::string timestamp(*fileContent);
        if (timeValidator->validateTimestamp(timestamp)) {
            if( !uniqueValueChecker->insertValue(timestamp.c_str())) {
                std::cerr << "Duplicate timestamp found: " << timestamp << std::endl;
            } else {
                outputGenerator->WriteOutputToFile(timestamp);
                outputGenerator->WriteOutputToFile("\n");
            }
        } else {
            std::cerr << "Invalid timestamp: " << timestamp << std::endl;
        }
        fileContent++;
    }
}    

