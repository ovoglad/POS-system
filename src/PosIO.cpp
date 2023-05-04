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
