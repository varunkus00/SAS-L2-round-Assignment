#include "OutputGenerator.h"

using namespace timestamp;

OutputGenerator::OutputGenerator() {
    filehandler = new FileHandler();
}

OutputGenerator::~OutputGenerator() {
    delete filehandler;
}

