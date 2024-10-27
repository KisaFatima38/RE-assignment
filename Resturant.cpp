#include "Restaurant.h"
#include <iostream>
#include <iomanip>
using namespace std;

Restaurant::Restaurant() 
{
    // Sample Menu Items
    menu.push_back(MenuItem(1, "Pasta", 12.99));
    menu.push_back(MenuItem(2, "Pizza", 9.99));
    menu.push_back(MenuItem(3, "Salad", 7.49));
    menu.push_back(MenuItem(4, "Soda", 2.49));
}

void Restaurant::displayMenu() const 
{
    cout << "----- Menu -----\n";
    for (const auto &item : menu) 
    {
        cout << item.id << ". " << item.name << " - $" << fixed << std::setprecision(2) << item.price << "\n";
    }
}

MenuItem* Restaurant::getMenuItem(int id) 
{
    for (auto &item : menu) 
    {
        if (item.id == id) 
        {
            return &item;
        }
    }
    return nullptr;
}

void Restaurant::createOrder(int tableNumber) 
{
    Order order(tableNumber);
    int choice;
    
    cout << "Enter item IDs to add to the order (0 to finish):\n";
    while (true) 
    {
        cout << "Item ID: ";
        cin >> choice;
        if (choice == 0) break;
        MenuItem* item = getMenuItem(choice);
        if (item) 
        {
            order.addItem(*item);
            cout << item->name << " added to the order.\n";
        } 
        else 
        {
            cout << "Invalid item ID.\n";
        }
    }
    orders.push_back(order);
    cout << "Order created for Table " << tableNumber << ".\n";
}

void Restaurant::displayBill(int tableNumber) const 
{
    for (const auto &order : orders) 
    {
        if (order.tableNumber == tableNumber) 
        {
            cout << "----- Bill for Table " << tableNumber << " -----\n";
            double total = 0;
            for (const auto &item : order.items) 
            {
                cout << item.name << " - $" << fixed << setprecision(2) << item.price << "\n";
                total += item.price;
            }
            cout << "Total: $" << fixed << setprecision(2) << total << "\n";
            return;
        }
    }
    cout << "No order found for Table " << tableNumber << ".\n";
}
