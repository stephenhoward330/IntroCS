/*
Stephen Howard, Section 3, stephenhoward330@gmail.com
Test Case 1: Name and date are entered, and menu is properly displayed
Input: John Deere 3/28/18 options
Output: Take name and date and display options menu
Passed
Test Case 2: Add, remove, and change quantity functions
Input: add pizza(yum yum, 2.50, 4), change quantity to 6, remove pizza
Output: pizza added, quantity changed, pizza removed
Passed
Test Case 3: Properly formats and outputs the print descriptions and print cart
Input: Pizza(yum yum, 2.50, 4), Soda(bad for ya, 1.25, 5)
Output: Pizza 4 @ $2.50 = $10.00, Soda 5 @ $1.25 = $6.25, Total: $16.25
		Pizza: yum yum, Soda: bad for ya
Passed
*/

#include <iostream>
#include <string>
#include "ShoppingCart.h"

using namespace std;

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
}

int main() {
	string customerName;
	string date;
	string userInput;
	string newItemName = "none";
	string newItemDescription = "none";
	double newItemPrice = 0.0;
	int newItemQuantity = 0;
	bool continueRunning = true;

	cout << "Enter Customer's Name: ";
	GetLineNotWS(customerName);

	cout << "Enter Today's Date: ";
	GetLineNotWS(date);
	cout << endl;

	ShoppingCart newShoppingCart(customerName, date);

	while (continueRunning) {
		cout << "Enter option: ";
		cin >> userInput;
		cout << endl;
		if (userInput == "add") {
			cout << "Enter the item name: ";
			GetLineNotWS(newItemName);
			cout << "Enter the item description: ";
			GetLineNotWS(newItemDescription);
			cout << "Enter the item price: ";
			cin >> newItemPrice;
			cout << "Enter the item quantity: ";
			cin >> newItemQuantity;
			cout << endl;

			ItemToPurchase newItem(newItemName, newItemDescription, newItemPrice, newItemQuantity);
			
			newShoppingCart.AddItem(newItem);
		}
		else if (userInput == "remove") {
			cout << "Enter name of the item to remove: ";
			GetLineNotWS(newItemName);

			newShoppingCart.RemoveItem(newItemName);
		}
		else if (userInput == "change") {
			cout << "Enter the item name: ";
			GetLineNotWS(newItemName);
			cout << "Enter the new quantity: ";
			cin >> newItemQuantity;

			newShoppingCart.UpdateItemQuantity(newItemName, newItemQuantity);
		}
		else if (userInput == "descriptions") {
			newShoppingCart.PrintDescriptions();
		}
		else if (userInput == "cart") {
			newShoppingCart.PrintNumAndCosts();
		}
		else if (userInput == "quit") {
			continueRunning = false;
			cout << "Goodbye." << endl;
		}
		else {
			cout << "MENU" << endl;
			cout << "add - Add item to cart" << endl;
			cout << "remove - Remove item from cart" << endl;
			cout << "change - Change item quantity" << endl;
			cout << "descriptions - Output items' descriptions" << endl;
			cout << "cart - Output shopping cart" << endl;
			cout << "options - Print the options menu" << endl;
			cout << "quit - Quit" << endl << endl;
		}
	}

	return 0;
}