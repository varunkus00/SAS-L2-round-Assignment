#include "TimestampWrapperClass.h"

using namespace timestamp;

TimeStampWrapperClass::TimeStampWrapperClass() {
    timeValidator = new TimeValidator();
    fileHandler = new FileHandler();
    outputGenerator = new OutputGenerator();
}

TimeStampWrapperClass::~TimeStampWrapperClass() {
    delete timeValidator;
    delete fileHandler;
    delete outputGenerator;
}

TimeValidator* TimeStampWrapperClass::getTimeValidator() {
    return timeValidator;
}

FileHandler* TimeStampWrapperClass::getFileHandler() {
    return fileHandler;
}

OutputGenerator* TimeStampWrapperClass::getOutputGenerator() {
    return outputGenerator;
}

