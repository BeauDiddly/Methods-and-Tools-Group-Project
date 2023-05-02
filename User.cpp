#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


class PaymentInformation {
private:
    string ccnum;
public:
    PaymentInformation(string ccNum);
    PaymentInformation();
    ~PaymentInformation();
    void setccnum(string num);
    string getccnum();
    void sendToFile();
};

class ShippingInformation {
private:
    string address;
public:
    ShippingInformation(string address);
    ShippingInformation();
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
    User();
    ~User();
    void setId(int Id);
    void setName(string Name);
    void setPaymentInfo(PaymentInformation info);
    void setShippingInfo(ShippingInformation info);
    void setHistory(History history);
    int getId();
    string getName();
    PaymentInformation getPaymentInfo();
    ShippingInformation getShippingInfo();
    History getHistory();
    void sendToFile();
};

User::User(int Id, string Name, PaymentInformation PaymentInfo, ShippingInformation shippingInfo, History history) {
    this->id = Id;
    this->name = Name;
    this->paymentInfo = PaymentInfo;
    this->shippingInfo = shippingInfo;
    this->history = history;
}

User::User() {
    id = 0;
    name = "N/A";
    paymentInfo = PaymentInformation();
    shippingInfo = ShippingInformation();
    history = History();
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
void User::setHistory(History history) {
    this->history = history;
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
History User::getHistory() {
    return history;
}

void User::sendToFile()
{
    ofstream file_obj;
    file_obj.open("User.dat", ios::app);
    file_obj << id << ",";
    file_obj << name << ",";
    file_obj << paymentInfo.getccnum() << ",";
    file_obj << shippingInfo.getAddress() << ",";



    int count = history.getHistory().size();
    for (size_t i = 0; i < count; i++)
    {
        file_obj << history.getHistory()[i] << ",";
    }
    file_obj << "\n";
    file_obj.close();
}

PaymentInformation::PaymentInformation(string ccNum) {
    this->ccnum = ccNum;
}

PaymentInformation::PaymentInformation() {
    ccnum = "0000000000000000";
}
PaymentInformation::~PaymentInformation() {
}
void PaymentInformation::setccnum(string num) {
    this->ccnum = num;
}
string PaymentInformation::getccnum() {
    return ccnum;
}

ShippingInformation::ShippingInformation(string address) {
    this->address = address;
}
ShippingInformation::ShippingInformation() {
    address = "123 Doesn't Exist St.";
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
    int count = history.size();
    for (int i = 0; i < count; i++) {
        cout << history[i] << "\n";
    }

}