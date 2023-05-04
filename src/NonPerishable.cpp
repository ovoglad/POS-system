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
