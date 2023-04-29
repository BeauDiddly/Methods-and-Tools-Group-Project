#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
private:
    int id;
    string name;
    PaymentInformation paymentInfo;
    ShippingInformation shippingInfo;
    History history;
public:
    User(int Id, string Name, PaymentInformation PaymentInfo, ShippingInformation shippingInfo, History history);
    ~User();
    void setId(int Id);
    void setName(string Name);
    void setPaymentInfo(PaymentInformation info);
    void setShippingInfo(ShippingInformation info);
    int getId();
    string getName();
    PaymentInformation getPaymentInfo();
    ShippingInformation getShippingInfo();
    void deleteUser();
};

class PaymentInformation {
private:
    int ccnum;
public:
    PaymentInformation(int ccNum);
    ~PaymentInformation();
    void setccnum(int num);
    int getccnum();
};

class ShippingInformation {
private:
    string address;
public:
    ShippingInformation(string address);
    ~ShippingInformation();
    void setAddress(string addy);
    string getAddress();
};

class History {
private:
    vector<int> history;
public:
    History();
    ~History();
    void addItem(int item);
    vector<int> getHistory();
    void viewHistory();
};

User::User(int Id, string Name, PaymentInformation PaymentInfo, ShippingInformation shippingInfo, History history) {
    this->id = Id;
    this->name = Name;
    this->paymentInfo = PaymentInfo;
    this->shippingInfo = shippingInfo;
    this->history = history;
}

User::~User() {};

void User::setId(int Id) {
    this->id = Id;
}
void User::setName(string Name) {
    this->name = Name;
}
void User::setPaymentInfo(PaymentInformation info) {
    this->paymentInfo = info;
}
void User::setShippingInfo(ShippingInformation info) {
    this->shippingInfo = info;
}

int User::getId() {
    return id;
}
string User::getName() {
    return name;
}
PaymentInformation User::getPaymentInfo() {
    return paymentInfo;
}
ShippingInformation User::getShippingInfo() {
    return shippingInfo;
}

void User::deleteUser() {
    this->~User();
}

PaymentInformation::PaymentInformation(int ccNum) {
    this->ccnum = ccNum;
}
PaymentInformation::~PaymentInformation() {
}
void PaymentInformation::setccnum(int num) {
    this->ccnum = num;
}
int PaymentInformation::getccnum() {
    return ccnum;
}

ShippingInformation::ShippingInformation(string address) {
    this->address = address;
}
ShippingInformation::~ShippingInformation() {};
void ShippingInformation::setAddress(string addy) {
    this->address = addy;
}
string ShippingInformation::getAddress() {
    return address;
}

History::History() {};
History::~History() {};
void History::addItem(int item) {
    history.push_back(item);
}
vector<int> History::getHistory() {
    return history;
}
void History::viewHistory() {
    cout << "User History: " << endl;
    for (int i = 0; i <= history.size(); i++) {
        cout << history.at(i) << " ";
    }
    cout << endl;
}