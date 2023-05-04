#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PosIO.h"

using namespace std;

namespace sdds {
    
    ostream& operator<<(ostream& os, const PosIO& posio) {
        posio.write(os);
        return os;
    }
    
    ofstream& operator<<(ofstream& ofs, const PosIO& posio) {
        posio.save(ofs);
        return ofs;
    }
    
    istream& operator>>(istream& is, PosIO& posio) {
        posio.read(is);
        return is;
    }
    
    ifstream& operator>>(ifstream& ifs, PosIO& posio) {
        posio.load(ifs);
        return ifs;
    }
        
}
