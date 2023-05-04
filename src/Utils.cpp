/*
*****************************************************************************
                        Milestone 5
Full Name  : Gladwin Chan
Student ID#: 130839228
Email      : gchan46@myseneca.ca
Section    : NBB
Date       : 2023-04-04

 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <string.h>
#include "Utils.h"

using namespace std;

namespace sdds {
    
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if(dateOnly) {
            hour = min = 0;
        } else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
    
    int uniqueDateValue(int year, int mon, int day, int hour, int min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    
    int daysOfMonth(int year, int month){
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
    void sortItemsByName(Item* items[], int size) {
        int i, j, minIdx;
        for (i = 0; i < size - 1; i++) {
            minIdx = i;
            for (j = i + 1; j < size; j++) {
                if (strcmp(items[j]->getName(), items[minIdx]->getName()) < 0) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(items[i], items[minIdx]);
            }
        }
    }

    
    
}
