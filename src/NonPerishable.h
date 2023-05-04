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

#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H

#include "Item.h"

namespace sdds {

    class NonPerishable : public Item {
      
    public:
        char itemType() const;
        std::ostream& write(std::ostream& os) const;
        std::ofstream& save(std::ofstream& ofs) const;

    };
    
}


#endif
