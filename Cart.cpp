#include <iostream>
#include <vector>
using namespace std;

class Cart
{
private:
    int User;
    vector<int> Items;
public:
    Cart(int user, vector<int> items);
    Cart();
    ~Cart();
    void setItems(vector<int> name);
    void setUser(int id);
    vector<int> getItems();
    int getUser();
    void addToCart(int item);
    void removeFromCart(int item);
    void emptyCart();
    void viewCart();
};

Cart::Cart(int user, vector<int> items) {
    this->User = user;
    this->Items = items;
}

Cart::Cart() {
    User = 0;
}

Cart::~Cart() {
}

void Cart::setItems(vector<int> name) {
    Items = name;
}

void Cart::setUser(int id) {
    User = id;
}

vector<int> Cart::getItems() {
    return Items;
}

int Cart::getUser() {
    return User;
}

void Cart::addToCart(int item) {
    Items.push_back(item);
}

void Cart::removeFromCart(int item) {
    for (int i = 0; i <= Items.size(); i++) {
        if (Items.at(i) == item) {
            Items.erase(Items.begin()+i);
        }
    }
    Items.shrink_to_fit();
}

void Cart::emptyCart() {
    Items.clear();
}

void Cart::viewCart() {
    cout << "Current Cart: " << endl;
    for (int i = 0; i <= Items.size(); i++) {
        cout << Items.at(i) << " ";
    }
    cout << endl;
}