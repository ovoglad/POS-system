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
