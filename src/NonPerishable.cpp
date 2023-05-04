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
#include "NonPerishable.h"
#include "Error.h"

using namespace std;

namespace sdds {
    
    char NonPerishable::itemType() const {
        return 'N';
    }
    
    ostream& NonPerishable::write(ostream& os) const {
        if(!m_error) {
            Item::write(os);
            
            if(m_displayType == POS_LIST) {
                os << "     N / A   |";
            } else if (m_displayType == POS_FORM) {
                os << "=============^" << endl;
            }
        }
        return os;
    }
    
    ofstream& NonPerishable::save(std::ofstream& ofs) const {
        Item::save(ofs);
        if (!m_error) {
            ofs << endl;;
        }
        return ofs;
    }
    
}
