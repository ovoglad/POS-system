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


#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include "Error.h"
#include "POS.h"
#include "Utils.h"

namespace sdds {
    
    class Date {
        int year=0;
        int month=0;
        int day=0;
        int hour=0;
        int minute=0;
        bool m_dateOnly=false;
        Error m_error;
        
    public:
        Date();
        Date(int year, int month, int day);
        Date(int year, int month, int day, int hour, int minute=0);
        bool isValid();
        std::ostream& display(std::ostream& ostr) const;
        Date& dateOnly(bool value);
        bool dateOnly() const;
        operator bool() const;
        const Error& error() const;
        std::istream& read(std::istream& istr);
        void setEmpty();
        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        Date(const Date& src);    
        Date& operator=(const Date& src);
        int getYear() const;
        int getMonth() const;
        int getDay() const;

    };
    
    std::ostream& operator<<(std::ostream& ostr, const Date& n);
    std::istream& operator>>(std::istream& istr, Date& n);

    
}

#endif


