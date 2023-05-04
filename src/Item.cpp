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
#include <iomanip>
#include <string.h>
#include "Item.h"

using namespace std;

namespace sdds {
    
    Item::Item() {
        m_SKU[0] = '\0';
        m_name = nullptr;
        m_price = 0.0;
        m_taxed = false;
        m_quantity = 0;
        m_displayType = 0;
    }
    
     Item::~Item() {
        delete[] m_name;
        m_name = nullptr;
    }
    
    Item::Item(const Item& src) {
        m_price = src.m_price;
        m_taxed = src.m_taxed;
        m_quantity = src.m_quantity;
        m_displayType = src.m_displayType;
        if(src.m_SKU[0] != '\0' && src.m_name) {
            strncpy(m_SKU, src.m_SKU, MAX_SKU_LEN);
            m_SKU[MAX_SKU_LEN]  = '\0';
            m_name = new char[strlen(src.m_name) + 1];
            strcpy(m_name, src.m_name);
        } else {
            m_SKU[0] = '\0';
            m_name = nullptr;
        }
    }
    
    Item& Item::operator=(const Item& src) {
        if (this != &src) {
            m_price = src.m_price;
            m_taxed = src.m_taxed;
            m_quantity = src.m_quantity;
            m_displayType = src.m_displayType;
            
            if (m_name != nullptr) {
                delete[] m_name;
                m_name = nullptr;
            }
            
            if (src.m_SKU[0] != '\0' && src.m_name) {
                strncpy(m_SKU, src.m_SKU, MAX_SKU_LEN);
                m_SKU[MAX_SKU_LEN] = '\0';
                m_name = new char[strlen(src.m_name) + 1];
                strcpy(m_name, src.m_name);
            } else {
                m_SKU[0] = '\0';
                m_name = nullptr;
            }
        }
            return *this;
    }
    /*bool Item::operator==(const Item& right) const {
        return (strcmp(m_SKU, right.m_SKU)==0);
    }*/
    bool Item::operator==(const char* sku) const {
        return (strcmp(m_SKU, sku) == 0);
    }

    
    bool Item::operator>(const Item& right) const {
        return (strcmp(m_name, right.m_name) > 0);
    }
    
    int Item::operator+=(int value) {
        m_quantity += value;
        if(m_quantity > MAX_STOCK_NUMBER) {
            m_quantity = MAX_STOCK_NUMBER;
            m_error.setErrorMessage(ERROR_POS_QTY);
        }
        return m_quantity;
    }
    
    int Item::operator-=(int value) {
        m_quantity -= value;
        if(m_quantity < 0) {
            m_quantity = 0;
            m_error = ERROR_POS_STOCK;
        }
        return m_quantity;
    }
    
    Item::operator bool() const {
        return (!m_error);
    }
    
    Item& Item::displayType(int form) {
        if(form == POS_LIST) {
            m_displayType = POS_LIST;
        } else if(form==POS_FORM){
            m_displayType = POS_FORM;
        }
        return *this;
    }
    
    double Item::cost() const {
        double fCost = 0.0;
        if(m_taxed) {
            fCost = m_price * (1+TAX);
        } else {
            fCost = m_price;
        }
        return fCost;
    }
    
    int Item::quantity() const {
        return m_quantity;
    }
    
    double& operator+=(double& left, const Item& right) {
        left += (right.cost() * right.quantity());
        return left;
    }
    
    Item& Item::clear() {
        m_error.Error::clear();
        return *this;
    }
    
    ostream& Item::write(ostream& os) const {
        if (!m_error) {
            if(m_displayType == POS_LIST) {
                os << setfill(' ') << setw(7) << left << m_SKU << "|";
                if(strlen(m_name) <= 20) {
                    os << setw(20) << m_name << "|";
                } else {
                    for(int i=0; i<20; i++) {
                        os << m_name[i];
                    }
                    os << "|";
                }
                os << setw(7) << right << fixed << setprecision(2) << m_price << "| ";
                os.unsetf(ios::right);
                if(m_taxed) {
                    os << "X |";
                } else {
                    os << "  |";
                }
                os << setw(4) << m_quantity << "|";
                os << setw(9) << fixed <<setprecision(2) << cost()*quantity() << "|";
            } else if(m_displayType == POS_FORM) {
                os << "=============v" << endl;
                os << setfill(' ') << setw(13) << left << "Name:" << m_name << endl;
                os << setw(13) << "Sku:" << m_SKU << endl;
                os << setw(13) << "Price:" << m_price << endl;
                os << setw(13) << "Price + tax:";
                if(m_taxed) {
                     os << fixed << setprecision(2) << cost() << endl;
                } else {
                    os << "N/A" << endl;
                }
                os << setw(13) << "Stock Qty:" <<  m_quantity << endl;
            }
        } else {
            os << m_error.getErrorMessage();
        }
        return os;
    }
    
    ofstream& Item::save(ofstream& ofs) const {
        if(!m_error) {
            ofs << itemType() << "," << m_SKU << "," << m_name << "," << fixed << setprecision(2) << m_price << "," << m_taxed << "," << m_quantity;
        } else {
            cerr << m_error << endl;
        }
        return ofs;
    }
   
    istream& Item::read(istream& is) {
        cout << "Sku" << endl;
        bool flag = true;
        while (flag) {
            cout << "> ";
            char tempSKU[50];
            is >> tempSKU;
            if (strlen(tempSKU) > MAX_SKU_LEN) {
                cout << ERROR_POS_SKU << endl;
                //m_error = ERROR_POS_SKU;
            } else {
                strncpy(m_SKU, tempSKU, MAX_SKU_LEN);
                flag = false;
            }
            is.ignore(1000, '\n');
        }
        
        cout << "Name" << endl;
        flag = true;
        while (flag) {
            cout << "> ";
            string tempName;
            getline(is, tempName);
            if (tempName.length() > MAX_NAME_LEN) {
                cout << ERROR_POS_NAME << endl;
                //m_error.setErrorMessage(ERROR_POS_NAME);
            } else {
                if (m_name != nullptr) {
                    delete[] m_name;
                    m_name = nullptr;
                }
                m_name = new char[tempName.length() + 1];
                strcpy(m_name, tempName.c_str());
                flag = false;
            }
        }
        
        cout << "Price" << endl;
        flag = true;
        while (flag) {
            cout << "> ";
            is >> m_price;
            if (!m_price || m_price < 0) {
                is.clear();
                is.ignore(1000, '\n');
                cout << ERROR_POS_PRICE << endl;
                //m_error.setErrorMessage(ERROR_POS_PRICE);
            } else {
                flag = false;
            }
        }

        cout << "Taxed?" << endl;
        cout << "(Y)es/(N)o: ";
        flag = true;
        while (flag) {
            char taxed;
            is >> taxed;
            if (taxed != 'y' && taxed != 'n') {
                cout << "Only 'y' and 'n' are acceptable: ";
                is.clear();
                is.ignore(1000, '\n');
            } else {
                if(taxed == 'y') {
                    m_taxed = true;
                    flag = false;
                } if (taxed == 'n') {
                    m_taxed = false;
                    flag = false;
                }
            }
        }

        cout << "Quantity" << endl;
        flag = true;
        while (flag) {
            cout << "> ";
            is >> m_quantity;
            if (!m_quantity || m_quantity < 0 || m_quantity >= 100) {
                is.clear();
                is.ignore(1000, '\n');
                cout << ERROR_POS_QTY << endl;
                //m_error.setErrorMessage(ERROR_POS_QTY);
            } else {
                flag = false;
            }
        }
        return is;
    }
    
    ifstream& Item::load(ifstream& ifs) {
        clear();
        m_SKU[0] = '\0';
        delete[] m_name;
        m_name = nullptr;
        m_price = 0;
        m_taxed = false;
        m_quantity = 0;
        m_displayType = -1;
        
        char tempSKU[50] = {};
        char tempName[60] = {};
        double tempPrice = 0.0;
        int tempTaxed = 0;
        int tempQty = 0;
        
        ifs.getline(tempSKU, 50, ',');
        ifs.getline(tempName, 60, ',');
        ifs >> tempPrice;
        ifs.ignore(1, ',');
        ifs >> tempTaxed;
        ifs.ignore(1, ',');
        ifs >> tempQty;
        
        if (strlen(tempSKU) > MAX_SKU_LEN) {
            m_error = ERROR_POS_SKU;
        } else if (strlen(tempName) > MAX_NAME_LEN) {
            m_error = ERROR_POS_NAME;
        } else if (tempPrice < 0) {
            m_error = ERROR_POS_PRICE;
        } else if (tempQty < 0 || tempQty >= 100) {
            m_error = ERROR_POS_QTY;
        }
      
        strncpy(m_SKU, tempSKU, MAX_SKU_LEN);
        m_name = new char[strlen(tempName) + 1];
        strcpy(m_name, tempName);
        m_price = tempPrice;
        if(tempTaxed == 1) {
            m_taxed = true;
        } else {
            m_taxed = false;
        }
        m_quantity = tempQty;

        return ifs;
    }
    
    ostream& Item::bprint(ostream& os) const {
        os << "| " << setfill(' ');
        if(strlen(m_name) <= 20) {
            os << setw(20) << left << m_name << "|";
        } else {
            for(int i=0; i<20; i++) {
                os << m_name[i];
            }
            os << "|";
        }
        os << right << setw(10);
        if(m_taxed) {
            os << fixed << setprecision(2) << cost(); //(m_price* (1+TAX))
        } else {
            os << fixed << setprecision(2) << cost();
        }
        os << " |  ";
        if(m_taxed) {
            os << "T  |" << endl;
        } else {
            os << "   |" << endl;
        }
        return os;
    }

    const char* Item::getName() const {
        return m_name;
    }

}
    
    

