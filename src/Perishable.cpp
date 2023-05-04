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
#include "Perishable.h"

using namespace std;

namespace sdds {
    
    /*Perishable::Perishable() : Item () {
        m_expiry.setEmpty();
    }
    
    Perishable::Perishable(const Perishable &src): Item(src) {
        m_expiry = src.m_expiry;
    }
    
    Perishable& Perishable::operator=(const Perishable& src) {
        if (this != &src) {
            Item::operator=(src);
            m_expiry = src.m_expiry;
        }
        return *this;
    }*/

    
    char Perishable::itemType() const {
        return 'P';
    }
    
    std::istream& Perishable::read(std::istream& is) {
        Item::read(is);
        
        if(!m_error && !is.fail()) {
            Date expiry;
            expiry.dateOnly(true);
            
            cout << "Expiry date (YYYY/MM/DD)" << endl;
            cout << "> ";
            is >> expiry;
            if(!expiry.error() && !is.fail()) {
                m_expiry = expiry;
            } else {
                this->m_error = expiry.error();
            }
        }
        return is;
    }
    
    ostream& Perishable::write(ostream& os) const {
        Item::write(os);

        if (!m_error) {
            if (m_displayType == POS_LIST) {
                os << "  " << m_expiry << " |";
            } else if (m_displayType == POS_FORM) {
                os << "Expiry date: " << m_expiry << endl;
                os << "=============^" << endl;
            }
        }
        return os;
    }
    
    ifstream& Perishable::load(ifstream& ifs) {
        Item::load(ifs);
        
        if(!m_error && !ifs.fail()) {
            Date expiry;
            expiry.dateOnly(true);
            ifs.ignore(1, ',');
            ifs >> expiry;
            if (!expiry.error()) {
                m_expiry = expiry;
            } else {
                this->m_error = expiry.error();
            }
        }
        return ifs;
    }

    ofstream& Perishable::save(std::ofstream& ofs) const {
        Item::save(ofs);
        if (!m_error) {
            ofs << "," << m_expiry << endl;;
        }
        return ofs;
    }

    
    
}
