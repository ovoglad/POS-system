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

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "Error.h"
#include "POS.h"
#include "PosIO.h"
#include <fstream>




namespace sdds {
    
    class Item : public PosIO {
        
    private:
        char m_SKU[MAX_SKU_LEN + 1];
        char* m_name;
        double m_price;
        bool m_taxed;
        int m_quantity;
        
    protected:
        int m_displayType;
        Error m_error;
        
    public:
        Item();
        virtual ~Item();
        Item(const Item& src);
        Item& operator=(const Item& src);
        bool operator==(const char* sku) const;
        //bool operator==(const Item& right) const;
        bool operator>(const Item& right) const;
        int operator+=(int value);
        int operator-=(int value);
        operator bool() const;
        virtual char itemType() const = 0; //?
        Item& displayType(int form);
        double cost() const;
        int quantity() const;
        Item& clear();
        bool isValid();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        std::ofstream& save(std::ofstream& ofs) const;
        std::ifstream& load(std::ifstream& ifs);
        std::ostream& bprint(std::ostream& os) const;
        const char* getName() const;
        
    };
    
    double& operator+=(double& left, const Item& right); //???
    
    
}



#endif
