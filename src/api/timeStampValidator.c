#include "api/timeStampValidator.h"

/*int hyfenCount(const char* timestamp) {
    int count = 0;
    int N = strlen(timestamp);
    for(int i = 0; i <N; i++ ) {
        if(timestamp[i] == 'T')
            break;
        if(timestamp[i] == '-')
            count++;
    }

    return count;
}

int colonCount(const char* timestamp) {
    int count = 0;
    int N = strlen(timestamp);
    for(int i = 0; i <N; i++ ) {
        if(timestamp[i] == ':')
            count++;
    }

    return count;
}

int plusCount(const char* timestamp) {
    int count = 0;
    int N = strlen(timestamp);
    for(int i = 0; i <N; i++ ) {
        if(timestamp[i] == '+')
            count++;
    }

    return count;
}

int minusCount(const char* timestamp) {
    int count = 0;
    int N = strlen(timestamp);
    int i = 0;
    while(timestamp[i] != 'T' && timestamp[i] != '\0') {
        i++;
    }

    for(; i < N; i++ ) {
        if(timestamp[i] == '-')
            count++;
    }

    return count;
}*/

void getSeperatorCount(const char* timestamp, int& hyfenCount, int& colonCount, int& plusCount, int& minusCount, bool& tzd) {

    int count = 0;
    int N = strlen(timestamp);
    bool isHourFormatIndicator = false;
    for(int i = 0; i <N; i++ ) {
        if(timestamp[i] == 'T')
            isHourFormatIndicator = true;
        if(timestamp[i] == '-' && isHourFormatIndicator == false )
            hyfenCount++;
        if(timestamp[i] == ':')
            colonCount++;
        if(timestamp[i] == '+')
            plusCount++;
        if(isHourFormatIndicator && timestamp[i] == '-')
            minusCount++;
        if(timestamp[i] == 'Z')
            tzd = true;
    }   

}

bool validateSeperators(const char* timestamp) {

    int hyfenCount = 0, colonCount = 0, plusCount = 0, minusCount = 0;
    bool tzd = false;

    getSeperatorCount(timestamp, hyfenCount, colonCount, plusCount, minusCount, tzd);

    if( hyfencount != 2) {
        return false;
    }

    if( coloncount < 2 || coloncount > 3) {
        return false;
    } else if( coloncount > 2 ) {
        int pluscount = plusCount(timestamp);
        int minuscount = minusCount(timestamp);

        if( pluscount != 1 && minuscount != 1) {
            return false;
        } else if( pluscount == 1 && minuscount == 1) {
            return false;
        }
    }    

    return true;
}

bool validateTimeStamp(const char* timestamp) {

    if( !timestamp) {
        return false;
    }

    if( !validateSeperators(timestamp) ) {
        return false;
    }
    //Count number of '-' in the timestamp
    

    return true;
}