using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Cart.cpp"
#include "Item.cpp"
#include "Stock.cpp"
#include "User.cpp"

User user;
Cart cart;
vector<Cart> listOfCarts;
vector<User> listOfUsers;
vector<Item> stock;
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
void setUsers();
void setCarts();
void setItems();

void setItems() {
    ifstream file_obj;
    string a, temp, word;
    vector<string> row;
    
    int roll2 = 0;
    file_obj.open("Item.dat", ios::in);
    while (file_obj >> temp) {
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(file_obj, a);
  
        // used for breaking words
        stringstream s(a);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
  
        // convert string to integer for comparision
        Item item;
        item.setName(row[0]);
        item.setCategory(stoi(row[1]));
        item.setId(stoi(row[2]));
        item.setCount(stoi(row[3]));
        stock.push_back(item);
    }
    file_obj.close();
}

void setCarts() {
    ifstream file_obj;
    string a, temp, word;
    vector<string> row;
    
    int roll2 = 0;
    file_obj.open("Cart.dat", ios::in);
    while (file_obj >> temp) {
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(file_obj, a);
  
        // used for breaking words
        stringstream s(a);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
  
        // convert string to integer for comparision
        Cart c;
        c.setUser(stoi(row[0]));
        for (int i = 1; row.size(); i++)
        {
            c.addToCart(stoi(row[i]));
        }
        listOfCarts.push_back(c);
        
    }
    file_obj.close();
}

void setUsers() {
    ifstream file_obj;
    string a, temp, word;
    vector<string> row;

    file_obj.open("User.dat", ios::in);
    while (getline(file_obj, temp)) {
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'a'
        getline(file_obj, a);
  
        // used for breaking words
        stringstream s(a);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
  
        // convert string to integer for comparision
        PaymentInformation pi = PaymentInformation(row[2]);
        ShippingInformation si = ShippingInformation(row[3]);
        History h;
        for (int i = 1; row.size(); i++)
        {
            h.addItem(stoi(row[i]));
        }
        

        User b = User(stoi(row[0]), row[1], pi, si, h);
        listOfUsers.push_back(b);
        
    }
    file_obj.close();
}
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
            if (login()) {
                loop = false;
            }   
        }
        else if (choice == 2)
        {
            createAccount();
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
    setUsers();
    string inputUsername;
    cout << "What is your Name?" << endl;
    cin.ignore();
    cin >> inputUsername;
    for (int i = 0; i < listOfUsers.size(); ++i)
    {
        if (listOfUsers[i].getName() == inputUsername)
        {
            user = listOfUsers[i];
            return true;
        }
        
    }
    
    cout << "That name doesn't exist\n";
    return false;
}
// ● Create Account
void createAccount() {
    string inputUsername, address, ccnum;
    int id, i;
    int prevIDs[100];
    cout << "What is your Name?" << endl;
    cin.ignore();
    getline(cin, inputUsername);
    cout << "What is your credit card number?" << endl;
    cin.ignore();
    getline(cin, ccnum);
    cout << "What is your address?" << endl;
    cin.ignore();
    getline(cin, address);
    user.setName(inputUsername);
    PaymentInformation a = PaymentInformation(ccnum);
    user.setPaymentInfo(a);
    ShippingInformation b = ShippingInformation(address);
    user.setShippingInfo(b);
    bool loop = true;
    while (loop)
    {
        loop = false;
        srand(time(NULL));
        id = rand();
        for (size_t i = 0; i < listOfUsers.size(); i++)
        {
            if (listOfUsers[i].getId() == id)
            {
                loop = true;
            }
        }
    }  
    user.setId(id);
    user.sendToFile();
}
// ● Exit Program
void exitProgram() {
    exit(0);
}
// After login:
void afterLogin() {
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
            saveUser();
            loop = false;
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
    cin.ignore();
    getline(cin, address);
    ShippingInformation si = ShippingInformation(address);
    user.setShippingInfo(si);
    for (size_t i = 0; i < listOfUsers.size(); i++)
    {
        if (listOfUsers[i].getId() == user.getId())
        {
            listOfUsers[i] = user;
        } 
    }
    saveUser();

}
// ○ Edit payment info
void editPaymentInfo() {
    string ccnum;
    cout << "What is your credit card number?" << endl;
    cin >> ccnum;
    PaymentInformation pi = PaymentInformation(ccnum);
    user.setPaymentInfo(pi);
    for (size_t i = 0; i < listOfUsers.size(); i++)
    {
        if (listOfUsers[i].getId() == user.getId())
        {
            listOfUsers[i] = user;
        } 
    }
    saveUser();

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
    cout << "Your account has been deleted and the program will end\n";    
}
// ○ Go back
void saveUser() {
    remove("User.dat");

    for (size_t i = 0; i < listOfUsers.size(); i++)
    {
        if (user.getId() == listOfUsers[i].getId())
        {
            listOfUsers[i] = user;
        }
        
        listOfUsers[i].sendToFile();
    }

}
// ● Cart Information
void cartInformation() {
    cart.emptyCart();

    for (size_t i = 0; i < listOfCarts.size(); i++)
    {
        if (listOfCarts[i].getUser() == user.getId())
        {
            cart = listOfCarts[i];
        }
    }
    bool loop = true;
    while (loop)
    {
        
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
    cart.emptyCart();
    user.setHistory(x);
}
// ○ Go back
void saveCart() {
    remove("Cart.dat");

    for (size_t i = 0; i < listOfUsers.size(); i++)
    {
        if (user.getId() == listOfUsers[i].getId())
        {
            listOfUsers[i] = user;
        }
        
        listOfUsers[i].sendToFile();
    }
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
    cout << "swag";
    setUsers();
    setCarts();
    setItems();
    beforeLogin();
    afterLogin();
}
