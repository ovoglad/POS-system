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

#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H

#include <fstream>

namespace sdds{
    
    class PosIO {
        
    public:
        
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual std::ofstream& save(std::ofstream& ofs) const = 0;
        virtual std::ifstream& load(std::ifstream& ifs) = 0;
        virtual ~PosIO() {};

    };
    
    std::ostream& operator<<(std::ostream& os, const PosIO& posio);
    std::ofstream& operator<<(std::ofstream& ofs, const PosIO& posio);
    std::istream& operator>>(std::istream& is, PosIO& posio);
    std::ifstream& operator>>(std::ifstream& ifs, PosIO& posio);

}




#endif
