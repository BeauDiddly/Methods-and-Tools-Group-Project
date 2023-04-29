using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Cart.cpp"
#include "Item.cpp"
#include "Stock.cpp"
#include "User.cpp"
// Before login:
User beforeLogin() {
    while (true)
    {
        int choice;
        cout << "What would you like to do?\n";
        cout << "   1. Login\n";
        cout << "   2. Create Account\n";
        cout << "   3. Exit Program\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            return login();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            exitProgram();
            break;

        default:
            cout << "Please choose an available option\n";
            break;
        }
    }
 
}
// ● Login
User login() {
    string inputUsername;
    cout << "What is your Name?\n";
    cin >> inputUsername;
    // Object to read from file
    ifstream file_obj;
    // Opening file in input mode
    file_obj.open("User.dat", ios::in);
    // Object of class User to input data in file
    User obj;
    // Reading from file into object "obj"
    file_obj.read((char*)&obj, sizeof(obj));
    while (!file_obj.eof()) {
        // Assigning max ratings
        if ((obj.getName() == inputUsername)) {
            return obj;
        }
        // Checking further
        file_obj.read((char*)&obj, sizeof(obj));
    }
    file_obj.close();
    cout << "That name doesn't exist\n";
    exit(0);
}
// ● Create Account
void createAccount() {
    string inputUsername, address;
    int ccnum, id, i;
    int prevIDs[100];
    cout << "What is your Name?\n";
    cin >> inputUsername;
    cout << "What is your credit card number?\n";
    cin >> ccnum;
    cout << "What is your address?\n";
    cin >> address;
    ifstream file_obj;
    // Opening file in input mode
    file_obj.open("User.dat", ios::in);
    // Object of class User to input data in file
    User obj;
    i = 0;
    // Reading from file into object "obj"
    file_obj.read((char*)&obj, sizeof(obj));
    while (!file_obj.eof()) {
        // Assigning max ratings
        prevIDs[i] = obj.getId();
        // Checking further
        file_obj.read((char*)&obj, sizeof(obj));
        i++;
    }
    file_obj.close();
    srand (time(NULL));
    bool check = true;
    while (check)
    {    
        check = false;
        id = rand();
        for (int j : prevIDs)
        {
            if (id == j)
            {
                check = true;
            }
        }
    }   
    User newUser = User(id, inputUsername, PaymentInformation(ccnum), ShippingInformation(address), History());
    ofstream file_obj2;
    file_obj2.open("User.dat", ios::app);
    file_obj2.write((char*)&newUser, sizeof(newUser));
    file_obj2.close();
    exit(0);
}
// ● Exit Program
void exitProgram() {
    exit(0);
}
// After login:
void afterLogin(User user) {
    int choice;
    cout << "What would you like to do?\n";
    cout << "   1. User Information\n";
    cout << "   2. Cart Information\n";
    cout << "   3. History\n";
    cout << "   4. Exit Program\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        userInformation(user);
        break;

    case 2:
        /* code */
        break;

    case 3:
        /* code */
        break;

    case 4:
        /* code */
        break;
    
    default:
        break;
    }
}
// ● User Information
void userInformation(User user) {
    bool loop = true;
    while (loop)
    {
        int choice;
        cout << "What would you like to do?\n";
        cout << "   1. Display User Info\n";
        cout << "   2. Edit Shipping Info\n";
        cout << "   3. Edi Payment Info\n";
        cout << "   4. Delete Account\n";
        cout << "   5. Go back\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayUserInfo(user);
            break;

        case 2:
            editShippingInfo();
            break;

        case 3:
            editPaymentInfo();
            break;

        case 4:
            deleteAccount();
            break;

        case 5:
            loop = false;
            break;
        default:
            cout << "Please choose an available option\n";
            break;
        }
    }
}
// ○ Display User Info
void displayUserInfo(User user) {
    cout << "id: " << user.getId() << "\n";
    cout << "name: " << user.getName() << "\n";
    
}
// ○ Edit shipping info
// ○ Edit payment info
// ○ Delete account
// ○ Go back
// ● Cart Information
// ○ View Cart
// ○ Remove Item from Cart
// ○ Add Item to Cart
// ○ Checkout
// ○ Go back
// ● History
// ○ Add order to history
// ○ View history
// ○ Go back
// ● Exit Program

int main() {
    afterLogin(beforeLogin());
}
