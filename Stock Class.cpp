#include <iostream>
#include <vector>
using namespace std;

class Stock
{
private:
    vector<int> Items;
public:
    Stock(vector<int> items);
    ~Stock();
    void setItems(vector<int> name);
    vector<int> getItems();
};

Stock::Stock(vector<int> items) {
    this->Items = items;
}

Stock::~Stock() {
}

void Stock::setItems(vector<int> name) {
    this->Items = name;
}

vector<int> Stock::getItems() {
    return Items;
}