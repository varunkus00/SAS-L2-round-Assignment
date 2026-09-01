#include <iostream>
#include "TimeValidator.h"
#include "FileHandler.h"
#include "OutputGenerator.h"


namespace timestamp {

    class TimeValidator;
    class FileHandler;
    class OutputGenerator;

    class TimeStampWrapperClass {

      public:
        TimeStampWrapperClass();
        ~TimeStampWrapperClass();

        TimeValidator* getTimeValidator();
        FileHandler* getFileHandler(); 
        OutputGenerator* getOutputGenerator();
         
      private:
        TimeValidator* timeValidator;
        FileHandler* fileHandler;
        OutputGenerator* outputGenerator;  
    };

}    