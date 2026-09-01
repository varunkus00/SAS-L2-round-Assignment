#include <iostream>
#include "TimeValidator.h"
#include "FileHandler.h"
#include "OutputGenerator.h"


namespace timestamp {

    class TimeValidator;
    class OutputGenerator;
    class InputFileReader;

    class TimeStampWrapperClass {

      public:
        TimeStampWrapperClass(const std::string& inputFileName, const std::string& outputFileName);
        ~TimeStampWrapperClass();

        TimeValidator* getTimeValidator(); 
        OutputGenerator* getOutputGenerator();
        InputFileReader* getInputFileReader();
        UniqueValueChecker* getUniqueValueChecker();
         
      private:
        TimeValidator* timeValidator;
        OutputGenerator* outputGenerator;  
        InputFileReader* inputFileReader;
        UniqueValueChecker* uniqueValueChecker;
    };

}    