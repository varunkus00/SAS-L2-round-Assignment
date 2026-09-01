#include "api/timeStampValidator.h"

int hyfenCount(const char* timestamp) {
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
}


bool validateTimeStamp(const char* timestamp) {

    if( !timestamp) {
        return false;
    }

    //Count number of '-' in the timestamp
    int hyfencount = hyfenCount(timestamp);
    if( hyfencount != 2) {
        return false;
    }

    //Count number of ':' in the timestamp
    int coloncount = colonCount(timestamp);
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