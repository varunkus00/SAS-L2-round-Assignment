#include "TimeValidator.h"

using namespace timestamp;

TimeValidator::TimeValidator(){
    month = 0;
    year = 0;
    date = 0;
    hour = 0;
    min = 0;
    sec = 0;
    tzd="";
}

TimeValidator::~TimeValidator(){
    month = 0;
    year = 0;
    date = 0;
    hour = 0;
    min = 0;
    sec = 0;
    tzd="";
}

int TimeValidator::GetYear(){
    return 0;
}

int TimeValidator::GetMonth(){
    return 0;
}

int TimeValidator::GetDate(){
    return 0;
}

int TimeValidator::GetHour(){
    return 0;
}

int TimeValidator::GetMin(){
    return 0;
}

int TimeValidator::GetSec(){
    return 0;
}

std::string TimeValidator::GetTZD(){
    return "";
}

bool TimeValidator::validateTimestamp(const std::string& timestamp){
    return validateTimeStamp(timestamp.c_str());
}