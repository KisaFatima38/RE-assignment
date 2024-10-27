#include "Order.h"

Order::Order(int tableNumber) : tableNumber(tableNumber) {}

void Order::addItem(const MenuItem &item) 
{
    items.push_back(item);
}

double Order::calculateTotal() const 
{
    double total = 0;
    for (const auto &item : items) 
    {
        total += item.price;
    }
    return total;
}
