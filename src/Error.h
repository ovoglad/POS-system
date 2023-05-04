#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
    
    class Error {
        char* errorMessage = nullptr;
        
    public:
        Error();
        ~Error();
        Error(const char* errorMessage);
        Error(const Error& src);
        Error& operator=(const Error& src);
        void setErrorMessage(const char* errorMessage); // no need for setter, equal assignment already done
        const char* getErrorMessage() const;
        bool operator==(const Error& right) const;
        operator bool() const;
        Error& clear();
        std::ostream& display(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Error& e);
    
}



#endif
