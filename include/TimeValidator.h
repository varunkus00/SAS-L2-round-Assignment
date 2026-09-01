#include <iostream>
#include "api/timeStampValidator.h"

namespace timestamp {


class TimeValidator {

public:
    TimeValidator();
    ~TimeValidator();

    int GetYear();
    int GetMonth();
    int GetDate();
    int GetHour();
    int GetMin();
    int GetSec();
    std::string GetTZD();
    bool validateTimestamp(const std::string& timestamp);

private:
    int month;
    int year;
    int date;
    int hour;
    int min;
    int sec;
    std::string tzd;

};

}