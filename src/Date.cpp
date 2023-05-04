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

#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Error.h"

using namespace std;

namespace sdds {
    
    Date::Date() {
        getSystemDate(year, month, day, hour, minute, m_dateOnly);
        m_dateOnly = false;
    }
    
    Date::Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
        m_dateOnly = true;
        isValid();
    }
    
    Date::Date(int year, int month, int day, int hour, int minute) {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        m_dateOnly = false;
        isValid();
    }
    
    bool Date::isValid() {
        bool ret = true;
        m_error.clear();
        if(year < MIN_YEAR || year > MAX_YEAR) {
            m_error = "Invalid Year";
            ret = false;
        }
        
        else if(month < 1 || month > 12) {
            m_error = "Invalid Month";
            ret = false;
        }
        
        else if(day < 1 || day > daysOfMonth(year, month)) {
            m_error = "Invalid Day";
            ret = false;
        }
        if (m_dateOnly == false) {
            if(hour < 0 || hour > 23) {
                m_error = "Invalid Hour";
                ret = false;
            }
            
            else if(minute < 0 || minute > 59) {
                m_error = "Invlid Minute";
                ret = false;
            }
        }
        return ret;
    }
    
    ostream& Date::display(ostream& ostr) const {
        if (m_dateOnly) {
            if (m_error) {
                ostr << m_error << "(" << year << "/";
                ostr << setfill('0') << setw(2) << month << "/";
                ostr << setfill('0') << setw(2) << day << ")";
            } else {
                ostr << year << "/";
                ostr << setfill('0') << setw(2) << right << month << "/";
                ostr << setfill('0') << setw(2) << right << day;
                ostr.unsetf(ios::right);
            }
        } else {
            if (m_error) {
                ostr << m_error << "(" << year << "/";
                ostr << setfill('0') << setw(2) << month;
                ostr << "/" << setfill('0') << setw(2) << day << ", ";
                ostr << setfill('0') << setw(2) << hour << ":";
                ostr << setfill('0') << setw(2) << minute << ")";
            } else {
                ostr << year << "/" << setfill('0') << setw(2) << month << "/";
                ostr << setfill('0') << setw(2) << day << ", ";
                ostr << setfill('0') << setw(2) << hour << ":";
                ostr << setfill('0') << setw(2) << minute;
            }
        }
        return ostr;
    }
    
    ostream& operator<<(ostream& ostr, const Date& n) {
        n.display(ostr);
        return ostr;
    }
    
    Date& Date::dateOnly(bool value){
        m_dateOnly = value;
        if(m_dateOnly) {
            hour = 0;
            minute = 0;
        }
        return *this;
    }
    
    bool Date::dateOnly() const {
        return m_dateOnly;
    }
    
    Date::operator bool() const {
        return !m_error;
    }
    
    const Error& Date::error() const {
        return m_error;
    }
    
    void Date::setEmpty() {
        this->year = 0;
        this->month = 0;
        this->day = 0;
        this->hour = 0;
        this->minute = 0;
    }
    
    istream & Date::read(istream & istr) {
        setEmpty();
        m_error.clear();
        istr >> year;
        if (!istr) {
            m_error = "Cannot read year entry";
        }
        istr.ignore();
        istr >> month;
        if (!m_error && !istr) {
            m_error = "Cannot read month entry";
        }
        istr.ignore();
        istr >> day;
        if (!m_error && !istr) {
            m_error = "Cannot read day entry";
        }
        if (!dateOnly()) {
            istr.ignore();
            istr >> hour;
            if (!m_error && !istr) {
                m_error = "Cannot read hour entry";
            }
            istr.ignore();
            istr >> minute;
            if (!m_error && !istr) {
                m_error = "Cannot read minute entry";
            }
        } else {
            hour = minute = 0;
        }
        if (istr) {
            isValid();
        }
        return istr;
    }
    
    istream& operator>>(istream& istr, Date& n) {
        n.read(istr);
        return istr;
    }
    
    bool Date::operator==(const Date& right) const {
        bool ret = false;
        if (year == right.year &&
            month == right.month &&
            day == right.day &&
            hour == right.hour &&
            minute == right.minute) {
            ret = true;
        } else {
            ret = false;
        }
        return ret;
    }
    
    bool Date::operator!=(const Date& right) const {
        return !(*this == right);
    }
    
    bool Date::operator<(const Date& right) const {
        bool ret = false;
        if (year < right.year) {
            ret = true;
        } else if (year == right.year) {
            if (month < right.month) {
                ret = true;
            } else if (month == right.month) {
                if (day < right.day) {
                    ret = true;
                } else if (day == right.day) {
                    if (hour < right.hour) {
                        ret = true;
                    } else if (hour == right.hour) {
                        if (minute < right.minute) {
                            ret = true;
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    bool Date::operator>(const Date& right) const {
        bool ret = false;
        if (year > right.year) {
            ret = true;
        } else if (year == right.year) {
            if (month > right.month) {
                ret = true;
            } else if (month == right.month) {
                if (day > right.day) {
                    ret = true;
                } else if (day == right.day) {
                    if (hour > right.hour) {
                        ret = true;
                    } else if (hour == right.hour) {
                        if (minute > right.minute) {
                            ret = true;
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    Date::Date(const Date& src) {
        year = src.year;
        month = src.month;
        day = src.day;
        hour = src.hour;
        minute = src.minute;
        m_dateOnly = src.m_dateOnly;
        m_error = src.m_error;
        
    }
    
    Date& Date::operator=(const Date& src) {
        if (this != &src) {
            year = src.year;
            month = src.month;
            day = src.day;
            hour = src.hour;
            minute = src.minute;
            m_dateOnly = src.m_dateOnly;
            m_error = src.m_error;
        }
        return *this;
    }
    
    int Date::getYear() const {
        return year;
    }
    
    int Date::getMonth() const{
        return month;
    }
    
    int Date::getDay() const {
        return day;
    }
    
}
