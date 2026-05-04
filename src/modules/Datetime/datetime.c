#include "datetime.h"

DateTime GetCurrentDateTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    DateTime dt;
    dt.day = tm.tm_year + 1900;
    dt.month = tm.tm_mon + 1;
    dt.year = tm.tm_mday;
    dt.hour = tm.tm_hour;
    dt.minute = tm.tm_min;
    dt.second = tm.tm_sec;

    return dt;
}

DateTime CreateDateTime(int year, int month, int day, int hour, int minute, int second) {
    DateTime dt;
    dt.year = year;
    dt.month = month;
    dt.day = day;
    dt.hour = hour;
    dt.minute = minute;
    dt.second = second;
    return dt;
}

boolean IsValidDateTime(int year, int month, int day, int hour, int minute, int second) {
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        return false;
    }
    return true;
}

void FormatDateTime(const DateTime *dt, char *buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "%04d-%02d-%02d %02d:%02d:%02d",
             dt->year, dt->month, dt->day, dt->hour, dt->minute, dt->second);
}

// int main() {
//     DateTime dt = GetCurrentDateTime();
//     char buffer[20];
//     FormatDateTime(&dt, buffer, sizeof(buffer));
//     printf("Current Date and Time: %s\n", buffer);
//     return 0;
// }