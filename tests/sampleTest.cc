#include <iostream>
#include "sample.h"
#include "TimeStampWrapperClass.h"

using namespace timestamp;

int main() {
    //print_message();

    TimeStampWrapperClass timestampWrapper("C:\\Users\\shriv\\SAS\\SAS-L2-round-Assignment\\InputTimeStamps", "C:\\Users\\shriv\\SAS\\SAS-L2-round-Assignment\\OutputTimeStamps");
    
    timestampWrapper.run();
    
    return 0;
}