#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include "MenuItem.h"
#include "Order.h"

class Restaurant 
{
private:
    std::vector<MenuItem> menu;
    std::vector<Order> orders;

public:
    Restaurant();
    void displayMenu() const;
    MenuItem* getMenuItem(int id);
    void createOrder(int tableNumber);
    void displayBill(int tableNumber) const;
};

#endif
