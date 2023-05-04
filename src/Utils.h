#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"

namespace sdds {
    
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min);
    int daysOfMonth(int year, int month);
    void sortItemsByName(Item* items[], int size);
}

#endif
