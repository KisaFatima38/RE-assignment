#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "MenuItem.h"

class Order 
{
public:
    int tableNumber;
    std::vector<MenuItem> items;

    Order(int tableNumber);
    void addItem(const MenuItem &item);
    double calculateTotal() const;
};

#endif
