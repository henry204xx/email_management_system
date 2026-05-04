#ifndef DATETIME_H
#define DATETIME_H

#include "../boolean.h" // Adjust the path as needed

#include <time.h>
#include <stdio.h>
#include <string.h>

// Define the DateTime structure
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateTime;

/* *** SELEKTOR *** */
#define Year(D) (D).year
#define Month(D) (D).month
#define Day(D) (D).day
#define Hour(D) (D).hour
#define Minute(D) (D).minute
#define Second(D) (D).second

/* *** KONSTRUKTOR *** */
DateTime GetCurrentDateTime();
/* Membentuk DateTime dari komponen-komponennya */

DateTime CreateDateTime(int year, int month, int day, int hour, int minute, int second);
/* Membentuk DateTime dari komponen-komponennya */

/* *** VALIDASI *** */
boolean IsValidDateTime(int year, int month, int day, int hour, int minute, int second);
/* Mengirim true jika year, month, day, hour, minute, second adalah representasi DateTime yang valid */

void FormatDateTime(const DateTime *dt, char *buffer, size_t bufferSize);
/* Mengubah tanggal dan waktu ke bentuk string untuk memudahkan output */

#endif // DATETIME_H