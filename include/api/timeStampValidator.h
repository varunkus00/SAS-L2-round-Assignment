#include <stdio.h>
#include <string.h>

//int hyfenCount(const char* timestamp);
//int colonCount(const char* timestamp);
//int plusCount(const char* timestamp);
//int minusCount(const char* timestamp);
void GetSeperatorCounts(const char* timestamp, int& hyfenCount, int& colonCount, int& plusCount, int& minusCount, bool& tzd);
bool validateSeperators(const char* timestamp);
bool validateMonth(const char* timestamp);
bool validateYear(const char* timestamp);
bool validateDate(const char* timestamp);
bool validateHour(const char* timestamp);
bool validateMin(const char* timestamp);
bool validateSec(const char* timestamp);
bool validateTZD(const char* timestamp);
bool validateTimeStamp(const char* timestamp);