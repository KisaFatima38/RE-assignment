#include "Restaurant.h"
#include <iostream>
using namespace std;

int main() 
{
    Restaurant restaurant;
    int choice;

    while (true) 
    {
        cout << "\n1. Display Menu\n2. Create Order\n3. Display Bill\n4. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) 
        {
            restaurant.displayMenu();
        } 
        else if (choice == 2) 
        {
            int tableNumber;
            cout << "Enter Table Number: ";
            cin >> tableNumber;
            restaurant.createOrder(tableNumber);
        } 
        else if (choice == 3) 
        {
            int tableNumber;
            cout << "Enter Table Number: ";
            cin >> tableNumber;
            restaurant.displayBill(tableNumber);
        } 
        else if (choice == 4) 
        {
            cout << "Exiting...\n";
            break;
        } 
        else 
        {
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
