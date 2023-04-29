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
int choice;
bool login();
void createAccount();
void exitProgram();
void userInformation();
void cartInformation();
void history();
void displayUserInfo(User usr);
void editShippingInfo();
void editPaymentInfo();
void deleteAccount();
void saveUser();
void viewCart();
void removeItem();
void addItem();
void checkout();
void saveCart();
void viewHistory();
// Before login:
void beforeLogin() {
    bool loop = true;
    while (loop)
    {
        cout << "What would you like to do?\n";
        cout << "   1. Login\n";
        cout << "   2. Create Account\n";
        cout << "   3. Exit Program\n";
        cin >> choice;
        if (choice == 1)
        {
            login();
            loop = false;
        }
        else if (choice == 2)
        {
            createAccount();
            cout << "here" << endl;
            loop = false;
        }
        else if (choice == 3)
        {
            exitProgram();
        }
        else {
            cout << "Please choose an available option\n";
        }
    } 
}
// ● Login
bool login() {
    string inputUsername;
    cout << "What is your Name?" << endl;
    cin >> inputUsername;
    // Object to read from file
    ifstream file_obj;
    // Opening file in input mode
    file_obj.open("User.dat", ios::in);
    // Object of class User to input data in file
    User obj;
    // Reading from file into object "obj"
    file_obj.read((char*)&obj, sizeof(obj));
    displayUserInfo(obj);
  
    while (!file_obj.eof()) {
        // Assigning max ratings
        if ((obj.getName() == inputUsername)) {
            user = obj;
            return true;
        }
        // Checking further
        file_obj.read((char*)&obj, sizeof(obj));
    }
    cout << "4" << endl;
    file_obj.close();
    cout << "That name doesn't exist\n";
    exit(0);
}
// ● Create Account
void createAccount() {
    string inputUsername, address, ccnum;
    int id, i;
    int prevIDs[100];
    cout << "What is your Name?" << endl;
    cin >> inputUsername;
    cout << "What is your credit card number?" << endl;
    cin >> ccnum;
    cout << "What is your address?" << endl;
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
    cout << id << endl;
    User newUser = User(id, inputUsername, PaymentInformation(ccnum), ShippingInformation(address), History());
    ofstream file_obj2;
    file_obj2.open("User.dat", ios::app);
    file_obj2.write((char*)&newUser, sizeof(newUser));
    file_obj2.close();
    user = newUser;
    displayUserInfo(user);
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
    cout << "What would you like to do?\n";
    cout << "   1. User Information\n";
    cout << "   2. Cart Information\n";
    cout << "   3. History\n";
    cout << "   4. Exit Program" << endl;
    cin >> choice;
    if (choice == 1)
    {
        userInformation();
    }
    else if (choice == 2)
    {
        cartInformation();
    }
    else if (choice == 3)
    {
        history();
    }
    else if (choice == 4)
    {
        cout << "You are now exiting the program";
        exit(0);
    }
    else {
        cout << "Please choose an available option\n";
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
        cout << "   3. Edit Payment Info\n";
        cout << "   4. Delete Account\n";
        cout << "   5. Go back" << endl;
        cin >> choice;
        if (choice == 1)
        {
            displayUserInfo(user);
        }
        else if (choice == 2)
        {
            editShippingInfo();
        }
        else if (choice == 3)
        {
            editPaymentInfo();
        }
        else if (choice == 4)
        {
            deleteAccount();
        }
        else if (choice == 5)
        {
            cout << "You are now exiting the program";
            exit(0);
        }
        else {
            cout << "Please choose an available option\n";
        }
    }
}
// ○ Display User Info
void displayUserInfo(User usr) {
    cout << "id: " << usr.getId() << "\n";
    cout << "name: " << usr.getName() << "\n";
    cout << "payment information: " << usr.getPaymentInfo().getccnum() << "\n";
    cout << "shipping information: " << usr.getShippingInfo().getAddress() << "\n";
    cout << "history:" << endl;
    vector<int> history = usr.getHistory().getHistory();
    for (size_t i = 0; i < history.size(); i++)
    {
        cout << "Item ID: " << history[i] << "\n";
    }
}
// ○ Edit shipping info
void editShippingInfo() {
    string address;
    cout << "What is your address?" << endl;
    cin >> address;
    user.setShippingInfo(address);
}
// ○ Edit payment info
void editPaymentInfo() {
    string ccnum;
    cout << "What is your credit card number?" << endl;
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
    for (size_t i = 0; i < listOfCarts.size(); i++)
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
        for (size_t i = 0; i < listOfCarts.size(); i++)
        {
            if (listOfCarts[i].getUser() == user.getId())
            {
                listOfCarts[i] = cart;
            }
        }
        
        int choice;
        cout << "What would you like to do?\n";
        cout << "   1. View Cart\n";
        cout << "   2. Remove Item from Cart\n";
        cout << "   3. Add Item to Cart\n";
        cout << "   4. Checkout\n";
        cout << "   5. Go back" << endl;
        cin >> choice;
        if (choice == 1)
        {
            viewCart();
        }
        else if (choice == 2)
        {
            removeItem();
        }
        else if (choice == 3)
        {
            addItem();
        }
        else if (choice == 4)
        {
            checkout();
        }
        else if (choice == 5)
        {
            loop = false;
            saveCart();
        }
        else {
            cout << "Please choose an available option\n";
        }
    }
}
// ○ View Cart
void viewCart() {
    cout << "Here is your cart"<< endl;
    for (size_t i = 0; i < cart.getItems().size(); i++)
    {
        cout << cart.getItems()[i] << "\n";
    }
}
// ○ Remove Item from Cart
void removeItem() {
    int input;
    cout << "What item would you like to remove? (please enter item ID)\n"<< endl;
    cin >> input;
    cart.removeFromCart(input);
}
// ○ Add Item to Cart
void addItem() {
    int input;
    cout << "What item would you like to add? (please enter item ID)\n"<< endl;
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
void saveCart() {
    remove("Cart.dat");
    ofstream file_obj("Cart.dat");
    file_obj.open("Cart.dat", ios::app);
    for (size_t i = 0; i < listOfCarts.size(); i++)
    {
        file_obj.write((char*)&listOfCarts[i], sizeof(listOfCarts[i]));
    }
    file_obj.close();
}
// ● History
void history() {
    bool loop = true;
    while (loop)
    {
        int choice;
        cout << "What would you like to do?\n";
        cout << "   1. View History\n";
        cout << "   2. Go back\n" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            viewHistory();
            break;

        case 2:
            loop = false;
            break;
        default:
            cout << "Please choose an available option\n" << endl;
            break;
        }
    }
}
// ○ Add order to history
// ○ View history
void viewHistory() {
    user.getHistory().viewHistory();
}
// ○ Go back
// ● Exit Program

int main() {
    beforeLogin();
    afterLogin();
}
