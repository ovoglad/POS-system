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

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h"
#include "Date.h"

namespace sdds {

    class Perishable : public Item {
        
    private:
        Date m_expiry;
        
    public:
        //Perishable();
        //~Perishable();
        //Perishable(const Perishable &src);
        //Perishable& operator=(const Perishable& src);
        
        char itemType() const;
        std::istream& read(std::istream& is);
        std::ostream& write(std::ostream& os) const;
        std::ifstream& load(std::ifstream& ifs);
        std::ofstream& save(std::ofstream& ofs) const;

    };
    
    
}


#endif
