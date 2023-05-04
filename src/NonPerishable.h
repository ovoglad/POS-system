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
