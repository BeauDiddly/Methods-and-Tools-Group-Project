using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Cart.cpp"
#include "Item.cpp"
#include "Stock.cpp"
#include "User.cpp"

User user;
Cart cart;
vector<Cart> listOfCarts;
Stock stock;
vector<User> listOfUsers;
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
            user = login();
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
void afterLogin() {
    ifstream file_obj;
    // Opening file in input mode
    file_obj.open("User.dat", ios::in);
    // Object of class User to input data in file
    User obj;
    // Reading from file into object "obj"
    file_obj.read((char*)&obj, sizeof(obj));
    while (!file_obj.eof()) {
        // Assigning max ratings
        listOfUsers.insert(listOfUsers.end(), obj);
        // Checking further
        file_obj.read((char*)&obj, sizeof(obj));
    }
    file_obj.close();

    file_obj.open("Cart.dat", ios::in);
    // Object of class User to input data in file
    // Reading from file into object "obj"
    file_obj.read((char*)&cart, sizeof(cart));
    while (!file_obj.eof()) {
        // Assigning max ratings
        listOfCarts.insert(listOfCarts.end(), cart);
        // Checking further
        file_obj.read((char*)&cart, sizeof(cart));
    }
    file_obj.close();

    file_obj.open("Stock.dat", ios::in);
    // Object of class User to input data in file
    
    // Reading from file into object "obj"
    file_obj.read((char*)&stock, sizeof(stock));
    file_obj.close();

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
        userInformation();
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
void userInformation() {
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
            displayUserInfo();
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
            saveUser();
            break;
        default:
            cout << "Please choose an available option\n";
            break;
        }
    }
}
// ○ Display User Info
void displayUserInfo() {
    cout << "id: " << user.getId() << "\n";
    cout << "name: " << user.getName() << "\n";
    cout << "payment information: " << user.getPaymentInfo().getccnum() << "\n";
    cout << "shipping information: " << user.getShippingInfo().getAddress() << "\n";
    cout << "history:\n";
    vector<int> history = user.getHistory().getHistory();
    for (size_t i = 0; i < history.size(); i++)
    {
        cout << "Item ID: " << history[i] << "\n";
    }
}
// ○ Edit shipping info
void editShippingInfo() {
    string address;
    cout << "What is your address?\n";
    cin >> address;
    user.setShippingInfo(address);
}
// ○ Edit payment info
void editPaymentInfo() {
    int ccnum;
    cout << "What is your credit card number?\n";
    cin >> ccnum;
    user.setPaymentInfo(ccnum);
}
// ○ Delete account
void deleteAccount() {
    int id = user.getId();
    for (size_t i = 0; i < listOfUsers.size(); i++)
    {
        if (id = listOfUsers[i].getId())
        {
            listOfUsers.erase(listOfUsers.begin()+i);
        }      
    }    
}
// ○ Go back
void saveUser() {
    remove("User.dat");
    ofstream file_obj("User.dat");
    file_obj.open("User.dat", ios::app);
    for (size_t i = 0; i < listOfUsers.size(); i++)
    {
        file_obj.write((char*)&listOfUsers[i], sizeof(listOfUsers[i]));
    }
    file_obj.close();
}
// ● Cart Information
void cartInformation() {
    bool loop = true;
    ifstream file_obj;
    // Opening file in input mode
    file_obj.open("Cart.dat", ios::in);
    // Object of class User to input data in file
    Cart obj;
    // Reading from file into object "obj"
    file_obj.read((char*)&obj, sizeof(obj));
    while (!file_obj.eof()) {
        if (obj.getUser() == user.getId())
        {
            break;
        } 
    }
    cart = obj;
    file_obj.close();
    while (loop)
    {
        int choice;
        cout << "What would you like to do?\n";
        cout << "   1. View Cart\n";
        cout << "   2. Remove Item from Cart\n";
        cout << "   3. Add Item to Cart\n";
        cout << "   4. Checkout\n";
        cout << "   5. Go back\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            viewCart();
            break;

        case 2:
            removeItem();
            break;

        case 3:
            addItem();
            break;

        case 4:
            checkout();
            break;

        case 5:
            loop = false;
            saveUser();
            break;
        default:
            cout << "Please choose an available option\n";
            break;
        }
    }
}
// ○ View Cart
void viewCart() {
    cout << "Here is your cart\n";
    for (size_t i = 0; i < cart.getItems().size(); i++)
    {
        cout << cart.getItems()[i] << "\n";
    }
}
// ○ Remove Item from Cart
void removeItem() {
    int input;
    cout << "What item would you like to remove? (please enter item ID)\n";
    cin >> input;
    cart.removeFromCart(input);
}
// ○ Add Item to Cart
void addItem() {
    int input;
    cout << "What item would you like to add? (please enter item ID)\n";
    cin >> input;
    cart.addToCart(input);    
}
// ○ Checkout
void checkout() {
    History x = user.getHistory();
    for (size_t i = 0; i < cart.getItems().size(); i++)
    {
        x.addItem(cart.getItems()[i]);
    }
    user.setHistory(x);
}
// ○ Go back
// ● History
// ○ Add order to history
// ○ View history
// ○ Go back
// ● Exit Program

int main() {
    afterLogin(beforeLogin());
}
