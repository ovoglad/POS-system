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
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
    
    class Error {
        char* errorMessage = nullptr;
        
    public:
        Error();
        ~Error();
        Error(const char* errorMessage);
        Error(const Error& src);
        Error& operator=(const Error& src);
        void setErrorMessage(const char* errorMessage); // no need for setter, equal assignment already done
        const char* getErrorMessage() const;
        bool operator==(const Error& right) const;
        operator bool() const;
        Error& clear();
        std::ostream& display(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Error& e);
    
}



#endif
