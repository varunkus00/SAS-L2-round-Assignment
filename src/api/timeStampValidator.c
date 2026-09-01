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


int colonCount(const char* timestamp, int stPos) {
    int count = 0;
    int N = strlen(timestamp);
    for(int i = stPos; i <N; i++ ) {
        if(timestamp[i] == ':')
            count++;
    }

    return count;


bool validateYear(const char* timestamp) {

    int i = 0;
    int N = strlen(timestamp);
    while( i < strlen(timestamp) && timestamp[i] != '-' )
        i++;

    if( i == N || i > 4 )
        return false;

    int k = 0;
    while( k < i ) {
        if( timestamp[i] < '0' && timestamp[i] > '9')
            return false;

        k++;    
    }

    return true;

}

bool validateMonth(const char* timestamp) {

    int i = 0;
    while( i < strlen(timestamp) && timestamp[i] != '-' )
        i++;

    int stPos = i+1;
    
    while( i < strlen(timestamp) && timestamp[i] != '-' )
        i++;

    if( i-stPos != 2 )
        return false;

    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;  
    
    if( timestamp[stPos] == '0' && timestamp[stPos+1] == '0' )
        return false;    
    if( timestamp[stPos] != '0' && timestamp[stPos] != '1' )
        return false;
    if( timestamp[stPos] == '1' && (timestamp[stPos+1] != '0' && timestamp[stPos+1] != '1' && timestamp[stPos+1] != '2') )
        return false;

    return true;    
}

bool validateDate(const char* timestamp) {

    int i = 0, count = 0;
    while( i < strlen(timestamp) && timestamp[i] != '-' && count != 2 ) {
        if( timestamp[i] == '-')
            count++;
        i++;
    }
        
    int stPos = i+1;
    
    while( i < strlen(timestamp) && timestamp[i] != 'T' )
        i++;

    if( i-stPos != 2 )
        return false;

    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;  
    
    if( timestamp[stPos] == '0' && timestamp[stPos+1] == '0' )
        return false;    
    if( timestamp[stPos] != '0' && timestamp[stPos] != '1' && timestamp[stPos] != '2' && timestamp[stPos] != '3' )
        return false;
    if( timestamp[stPos] == '3' && ( timestamp[stPos+1] != '0' && timestamp[stPos+1] != '1') )
        return false;

    return true;    
}



bool validateHour(const char* timestamp) {

    int i = 0, count = 0;
    while( i < strlen(timestamp) && timestamp[i] != 'T' ) {
        i++;
    }
    
    if( i == strlen(timestamp) )
        return false;

    int stPos = i+1;
    
    while( i < strlen(timestamp) && timestamp[i] != ':' )
        i++;

    if( i == strlen(timestamp) )
        return false;

    if( i-stPos != 2 )
        return false;
 
    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;    
        
    if( timestamp[stPos] != '0' && timestamp[stPos] != '1' && timestamp[stPos] != '2' )
        return false;
    if( timestamp[stPos] == '2' && ( timestamp[stPos+1] != '0' && timestamp[stPos+1] != '1' && timestamp[stPos+1] != '2' && timestamp[stPos+1] != '3') )
        return false;

    return true;    
}

bool validateMin(const char* timestamp) {

    int i = 0, count = 0;
    while( i < strlen(timestamp) && timestamp[i] != ':' ) {
        i++;
    }
    
    if( i == strlen(timestamp) )
        return false;

    int stPos = i+1;
    
    while( i < strlen(timestamp) && timestamp[i] != ':' )
        i++;

    if( i == strlen(timestamp) )
        return false;

    if( i-stPos != 2 )
        return false;
 
    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;    
        
    if( timestamp[stPos] > '5' )
        return false;

    return true;    
}

bool validateSec(const char* timestamp) {

    int i = 0, count = 0;
    while( i < strlen(timestamp) && timestamp[i] != ':' && count != 2 ) {
        if( timestamp[i] != '+' || timestamp[i] != '-')
            break;
        if( timestamp[i] == ':')
            count++;
        i++;
    }
    
    if( i == strlen(timestamp) || count != 2 )
        return false;

    int stPos = i+1;
    
    while( i < strlen(timestamp) && ( timestamp[i] != 'Z' || timestamp[i] != '+' || timestamp[i] != '-' )  )
        i++;

    if( i == strlen(timestamp) )
        return false;

    if( i-stPos != 2 )
        return false;
 
    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;    
        
    if( timestamp[stPos] > '5' )
        return false;

    return true;    
}

bool validateTZD(const char* timestamp) {

    int i = 0;
    int N = strlen(timestamp);
    if( timestamp[N-1] == 'Z' )
        return true;
    
    while( i < N && (timestamp[i] != '+' || timestamp != '-') ) {
        i++;
    }  

    if( i == N )
        return false;

    if( colonCount(timestamp, i) != 1 )
        return false;    

    int k = i;
    while( k < N ) {
        if( (timestamp[k] < '0' && timestamp[k] > '9') || (timestamp[i] != ':'))
            return false;

        k++;    
    }

    int stPos = i+1;
    
    while( i < strlen(timestamp) && timestamp[i] != ':' )
        i++;

    if( i == strlen(timestamp) )
        return false;

    if( i-stPos != 2 )
        return false;
 
    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;    
        
    if( timestamp[stPos] != '0' && timestamp[stPos] != '1' && timestamp[stPos] != '2' )
        return false;
    if( timestamp[stPos] == '2' && ( timestamp[stPos+1] != '0' && timestamp[stPos+1] != '1' && timestamp[stPos+1] != '2' && timestamp[stPos+1] != '3') )
        return false;
    
    stPos = i+1;
    
    while( i < strlen(timestamp) && timestamp[i] != ':' )
        i++;

    if( i == strlen(timestamp) )
        return false;

    if( i-stPos != 2 )
        return false;
 
    if( timestamp[stPos] < '0' && timestamp[stPos+1] > '9' )
        return false;    
        
    if( timestamp[stPos] > '5' )
        return false;
    
    return true;    

}

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
    
    if( !validateYear(timestamp) || !validateMonth(timestamp) || !validateDate(timestamp) || !validateHour(timestamp) || !validateMin(timestamp) || !validateSec(timestamp) || !validateTZD(timestamp) ||) {
        return false;
    }
    
    return true;
}