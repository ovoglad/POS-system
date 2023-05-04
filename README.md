# Point of Sale System

This is a C++ project for a point of sale system that allows for listing, adding, removing and stocking items in a store. The system can read from a text file and write out to a text file including information such as SKU, item name, price, taxable status , quantity and expiry date. It can also perform point of sale transactions, selling items to customers and generating receipts. 

## Installation

To use this program, simply compile the source and header files. The program will prompt you with a menu of options to choose from. You can navigate the menu by entering the number corresponding to the option you want to select.

## Features
1. List items
2. Add item
3. Remove item
4. Stock item
5. POS
0. Exit program

### List all items

This option will display a list of all items in store, including SKU, item name, price, taxable status, quantity, total price, and expiry date. 

### Add an item

This options allows you to add a new item to the store. You will be prompted to item’s information, including if the type of item (perishable or non-perishable), SKU, item name, price, taxable status, and quantity. 


### Remove an item

This option allows you to remove an existing item from the store. You will be prompted to enter the numbered item you want to remove.

### Stock an item

This options allows you to add stock to an existing item. You will be prompted to enter the numbered item and the quantity of stock to add.

### POS

This option allows you to sell an item to a customer. You will be prompted to enter the SKU of the items to be purchased. The system will generate a receipt with the current date and time, items purchased, and total cost of transaction including any applicable taxes.

### Exit Program

This option will exit the program. 

## Contributors

The point of sale system was a school project created by Gladwin Chan. All of the code for the project was written by myself, with the exception of the billing module which was provided by professor Fardad Soleimanloo.


