#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Error.h"


using namespace std;

namespace sdds {
    
    Error::Error() {
        errorMessage = nullptr;
    }
    
    Error::~Error() {
        delete [] errorMessage;
    }
    
    Error::Error(const char* errorMessage) {
        if(errorMessage[0] != '\0') {
            this->errorMessage = new char[strlen(errorMessage) + 1];
            strcpy (this->errorMessage, errorMessage);
        } else {
            this->errorMessage = nullptr;
        }
    }
    
    Error::Error(const Error& src) {
        if (src.errorMessage != nullptr) {
            this->errorMessage = new char[strlen(src.errorMessage) + 1];
            strcpy(this->errorMessage, src.errorMessage);
        } else {
            this->errorMessage = nullptr;
        }
    }
    
    Error& Error::operator=(const Error& src) {
        if (this != &src) {
            delete[] errorMessage;
            errorMessage = nullptr;
            if (src.errorMessage != nullptr) {
                this->errorMessage = new char[strlen(src.errorMessage) + 1];
                strcpy(this->errorMessage, src.errorMessage);
            } else {
                this->errorMessage = nullptr;
            }
        }
        return *this;
    }

    void Error::setErrorMessage(const char* errorMessage) {
        if(errorMessage != nullptr && errorMessage[0] != '\0') {
            if(this->errorMessage) {
                delete[] this->errorMessage;
                this->errorMessage = nullptr;
            }
            this->errorMessage = new char[strlen(errorMessage) + 1];
            strcpy(this->errorMessage, errorMessage);
        } else {
            this->errorMessage = nullptr;
        }
    }
    
    const char* Error::getErrorMessage() const {
        return errorMessage;
    }
    
   bool Error::operator==(const Error& right) const {
       bool ret = false;
       if(this->errorMessage == nullptr || right.errorMessage == nullptr) {
           ret = false;
       } else {
           return (strcmp(this->errorMessage, right.errorMessage) == 0);
       }
       return ret;
    }
    
    Error::operator bool() const {
        return errorMessage != nullptr;
    }

    Error& Error::clear() {
        if(errorMessage != nullptr) {
            delete[] errorMessage;
            errorMessage = nullptr;
        }
        return *this;
    }
    
    std::ostream& Error::display(std::ostream& os) const {
        if(errorMessage) {
            os << errorMessage;
        }
        return os;
    }

    
    std::ostream& operator<<(std::ostream& os, const Error& e) {
        return e.display(os);
    }
    
    
    
    
}





