#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

#define MAX_FILE_NAME 128
#include "POS.h"
#include "Item.h"

namespace sdds {
    
    class PosApp {
        char filename[MAX_FILE_NAME +1];
        Item* Iptr[MAX_NO_ITEMS];
        int nptr;

        void menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems(bool displayTotal);
        int selectItem();
        void POS();
        void saveRecs();
        void loadRecs();
    
    public:
        PosApp();
        PosApp(const char* filename);
        ~PosApp();
        PosApp(const PosApp& src) = delete;
        PosApp& operator=(const PosApp& src) = delete;
        void run();
        PosApp& clear();
        Item* search(const char* sku) const;
    };
    
}


#endif
