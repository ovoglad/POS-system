# Point of Sale System

This is a C++ project for a point of sale system that allows for listing, adding, removing and stocking items in a store. The system can read from a text file and write out to a text file including information such as SKU, item name, price, taxable status , quantity and expiry date. It can also perform point of sale transactions, selling items to customers and generating receipts. 

## Implementation

This program was implemented using the following concepts:

### Encapsulation

Encapsulation was used to protect the internal data of classes. Each class has private member variables and public members functions that allow for controlled access to these variables. 

### Inheritance

Inheritance was used two create two derived classes: ‘NonPerishable’ and ‘Perishable’. Both of these classes inherit from ‘Item’ base class. The derived classes inherit the member variables and functions of the base class. The ‘Perishable’ class has an extra data member for expiry date. 

### Polymorphism using Virtual Functions

Virtual functions: ‘read()’, ‘write()’, ‘load()’ and ‘save()’ are defined in a base class and overridden in the derived classes. These are defined in the ‘Item’ class and overridden in the derived ‘NonPerishable’ and ‘Perishable’ derived classes. These virtual functions provide the appropriate read and write operations for each item type.

## Installation

To use this program, simply compile the source and header files. The program will prompt you with a menu of options to choose from. You can navigate the menu by entering the number corresponding to the option you want to select.

## Features

### 1. List all items

This option will display a list of all items in store, including SKU, item name, price, taxable status, quantity, total price, and expiry date. 

### 2. Add an item

This options allows you to add a new item to the store. You will be prompted to item’s information, including if the type of item (perishable or non-perishable), SKU, item name, price, taxable status, and quantity. 


### 3. Remove an item

This option allows you to remove an existing item from the store. You will be prompted to enter the numbered item you want to remove.

### 4. Stock an item

This options allows you to add stock to an existing item. You will be prompted to enter the numbered item and the quantity of stock to add.

### 5. POS

This option allows you to sell an item to a customer. You will be prompted to enter the SKU of the items to be purchased. The system will generate a receipt with the current date and time, items purchased, and total cost of transaction including any applicable taxes.

### 6. Exit Program

This option will exit the program. 


