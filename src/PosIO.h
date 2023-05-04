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
