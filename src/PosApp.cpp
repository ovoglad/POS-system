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
#include <string.h>
#include <limits>
#include <iomanip>
#include "PosApp.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Utils.h"
#include "Bill.h"

using namespace std;

namespace sdds {
    
    PosApp::PosApp () {
        filename[0] = '\0';
        nptr = 0;
    }
    
    PosApp::PosApp(const char* filename) {
        if (filename[0] != '\0') {
            strcpy(this->filename, filename);
        }
        nptr = 0;
    }
    
    void PosApp::run() {
        loadRecs();
        
        bool validSelection = false;
        int selection = -1;
        
        while (selection != 0) {
            menu();
            
            while (!validSelection) {
                if (!(cin >> selection)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Integer, try again: ";
                    validSelection = false;
                } else if (!(selection >= 0 && selection <= 5)) {
                    cout << "[0<=value<=5], retry: > ";
                    validSelection = false;
                } else {
                    validSelection = true;
                }
            }
            
            switch(selection) {
                case 1:
                    cout << ">>>> Listing Items..........................................................." << endl;
                    listItems(true);
                    break;
                case 2:
                    cout << ">>>> Adding Item to the store................................................" << endl;
                    addItem();
                    break;
                case 3:
                    cout << ">>>> Remove Item............................................................." << endl;
                    cout << ">>>> Item Selection by row number............................................" << endl;
                    cout << "Press <ENTER> to start...." << endl;
                    cout << ">>>> Listing Items..........................................................." << endl;
                    removeItem();
                    break;
                case 4:
                    cout << ">>>> Select an item to stock................................................." << endl;
                    cout << ">>>> Item Selection by row number............................................" << endl;
                    cout << "Press <ENTER> to start...." << endl;
                    cout << ">>>> Listing Items..........................................................." << endl;
                    stockItem();
                    break;
                case 5:
                    cout << ">>>> Starting Point of Sale.................................................." << endl;
                    POS();
                    break;
                case 0:
                    cout << ">>>> Saving Data............................................................." << endl;
                    saveRecs();
                    cout << "Goodbye!" << endl;
                    break;
            }
            validSelection = false;
        }
    }
    
    void PosApp::menu() {
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" <<endl;
        cout << "4- Stock item" << endl;
        cout << "5- POS" << endl;
        cout << "0- exit program" << endl;
        cout << "> ";
    }
    
    void PosApp::addItem() {
        if(nptr == MAX_NO_ITEMS) {
            cout << "Inventory Full!" << endl;
            return;
        }
        
        Item* item = nullptr;
        cout << "Is the Item perishable? (Y)es/(N)o: ";
        char yesNo;
        cin >> yesNo;
        if(yesNo == 'y' || yesNo == 'Y') {
            item = new Perishable();
        } else if (yesNo == 'n' || yesNo == 'N') {
            item = new NonPerishable();
        }
        
        bool flag = false;
        while (!flag) {
            cin >> *item;
            
            if(cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << *item << ", try again..." << endl;
                flag = false;
            } else {
                Iptr[nptr] = item;
                nptr++;
                flag = true;
            }
        }
        cout << ">>>> DONE!................................................................." << endl;
    }
    
    void PosApp::removeItem() {
        int row = selectItem();
        cout << "Removing...." << endl;
        Iptr[row-1]->displayType(POS_FORM);
        Iptr[row-1] -> write(cout);
        delete Iptr[row - 1];
        for (int i = row - 1; i < nptr - 1; i++) {
            Iptr[i] = Iptr[i + 1];
        }
        nptr--;
        cout << ">>>> DONE!................................................................." << endl;
    }
    
    void PosApp::stockItem() {
        int row = selectItem();
        cout << "Selected Item:" << endl;
        Iptr[row-1]->displayType(POS_FORM);
        Iptr[row-1] -> write(cout);
        cout << "Enter quantity to add: ";
        bool valid = false;
        int quantity;
        while (!valid) {
            cin >> quantity;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, try again: ";
            } else if(quantity < 1 || quantity >= MAX_STOCK_NUMBER - Iptr[row-1]->quantity()) {
                cout << "[1<=value<=" << (MAX_STOCK_NUMBER - Iptr[row-1]->quantity()) << "], retry: Enter quantity to add: ";
            } else {
                *Iptr[row-1] += quantity;
                cout << ">>>> DONE!................................................................." << endl;
                valid = true;
            }
        }
    }
    
    void PosApp::listItems(bool displayTotal) {
        cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
        cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
        double totalAsset = 0;
        
        sortItemsByName(Iptr, nptr);
        
        for (int i = 0; i < nptr; i++) {
            cout << setw(4) << setfill(' ') << i + 1 << " | ";
            Iptr[i] -> displayType(POS_LIST);
            Iptr[i] -> write(cout);
            totalAsset += Iptr[i]->cost() * Iptr[i]->quantity();
            cout << endl;
        }
        cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
        if(displayTotal) {
            cout << "                               Total Asset: $  |";
            cout << setw(14) << setfill(' ') << totalAsset << "|" << endl;;
            cout << "-----------------------------------------------^--------------^" << endl << endl;
        }
    }
    
    int PosApp::selectItem() {
        listItems(false);
        cout << "Enter the row number: ";
        int row = 0;
        bool valid = false;
        while (!valid) {
            cin >> row;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, try again: ";
            } else if(row < 1 || row > nptr) {
                cout << "[1<=value<=" << nptr << "], retry: Enter the row number: ";
            } else {
                valid = true;
            }
        }
        return row;
    }
    
    void PosApp::POS() {
        cin.ignore();
        Bill bill;
        char SKU[MAX_SKU_LEN+1];
        bool loop = true;
        
        while(loop) {
            cout << "Enter SKU or <ENTER> only to end sale..." << endl;
            cout << "> ";
            cin.getline(SKU, MAX_SKU_LEN);
            if(strlen(SKU) == 0) {
                loop = false;
            } else {
                Item* item = search(SKU);
                if(item == nullptr) {
                    cout << "!!!!! Item Not Found !!!!!" << endl;
                }
                else if(item -> quantity() > 0) {
                    (*item) -= 1;
                    item -> displayType(POS_FORM);
                    item -> write(cout);
                    bill.add(item);
                    cout << endl << ">>>>> Added to bill" << endl;
                    cout << ">>>>> Total: " << bill.total() << endl;
                } else {
                    cout << "Item out of stock" << endl;
                }
            }
        }
        bill.print(cout);
    }
    
    
    void PosApp::saveRecs() {
        ofstream output(filename);
        if(output) {
            for(int i = 0; i < nptr; i++) {
                Iptr[i]->save(output);
            }
            output.close();
        }
    }
    
    void PosApp::loadRecs() {
        cout << ">>>> Loading Items..........................................................." << endl;
        ifstream input(filename);
        
        if(input.fail()) {
            ofstream file(filename);
            file.close();
        }
        
        clear();
        
        while(input && nptr < MAX_NO_ITEMS) {
            char itemType;
            input >> itemType;
            if (input) {
                Item* item = nullptr;
                if(itemType == 'P') {
                    item = new Perishable();
                } else if(itemType == 'N') {
                    item = new NonPerishable();
                }
                input.ignore();
                if (item) {
                    item->load(input);
                    Iptr[nptr++] = item;
                }
            }
        }
    }
    
    PosApp& PosApp::clear() {
        for(int i = 0; i < nptr; i++) {
            delete Iptr[i];
            Iptr[i] = nullptr;
        }
        nptr = 0;
        return *this;
    }
    
    PosApp::~PosApp() {
        clear();
    }
    
    Item* PosApp::search(const char* sku) const {
        for (int i = 0; i < nptr; i++) {
            if(*Iptr[i] == sku) {
                return Iptr[i];
            }
        }
        return nullptr;
    }

    
    
}

