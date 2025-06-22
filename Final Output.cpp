// Final Output.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;

// Structure for User
struct User {
    string name;
    string email;
    string password;
    bool isAdmin;
    bool isActive;
};

// Global user list with one default admin
vector<User> users = {
    {"Admin", "admin@sys.com", "Admin123", true, true},
    {"UserOne", "user1@example.com", "User1234", false, true},
    {"UserTwo", "user2@example.com", "User5678", false, true}
};

// Pricing map
unordered_map<string, double> pricing = {
    {"Print", 0.20},
    {"Scan", 0.10}
};

// Validate email format
bool validateEmail(string input) {
    regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return regex_match(input, pattern);
}

// Validate strong password
bool validatePassword(string input) {
    regex pattern("^(?=.*[A-Z])(?=.*\\d).{8,}$");
    return regex_match(input, pattern);
}

// User registration function
void registerUser() {
    User user;
    cout << "Enter name: ";
    cin >> user.name;

    if (user.name.empty()) {
        cout << "Name cannot be empty." << endl;
        return;
    }

    do {
        cout << "Enter email: ";
        cin >> user.email;
        if (!validateEmail(user.email)) {
            cout << "Invalid email format." << endl;
        }
    } while (!validateEmail(user.email));

    do {
        cout << "Enter strong password (min 8 chars, 1 uppercase, 1 digit): ";
        cin >> user.password;
        if (!validatePassword(user.password)) {
            cout << "Invalid password. Try again." << endl;
        }
    } while (!validatePassword(user.password));

    user.isAdmin = false;
    user.isActive = true;
    users.push_back(user);
    cout << "Registration successful!" << endl;
}

// Login function
int login(string& email) {
    string password;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].email == email && users[i].password == password && users[i].isActive) {
            return i;
        }
    }
    return -1;
}


void showActiveUsers() {
    cout << "\nActive Users:" << endl;
    for (const auto& user : users) {
        if (user.isActive) {
            cout << "- " << user.email << endl;
        }
    }
}


void deleteUser() {
    string targetEmail;
    cout << "Enter the email of the user to inactivate: ";
    cin >> targetEmail;

    bool found = false;
    for (auto& user : users) {
        if (user.email == targetEmail && user.isActive) {
            user.isActive = false;
            cout << "User " << user.email << " has been inactivated." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "User not found or already inactive." << endl;
    }
}

// Update pricing
void updatePricing() {
    string service;
    double newPrice;
    cout << "Enter service to update (Print/Scan): ";
    cin >> service;

    
    for (auto& c : service) c = toupper(c);

    if (service == "PRINT" || service == "SCAN") {
        string key = (service == "PRINT") ? "Print" : "Scan";
        cout << "Current price for " << key << ": $" << pricing[key] << endl;
        cout << "Enter new price: $";
        cin >> newPrice;
        pricing[key] = newPrice;
        cout << key << " price updated to $" << newPrice << endl;
    }
    else {
        cout << "Invalid service name." << endl;
    }
}

// Print documents
void printDocuments() {
    int pages;
    cout << "Enter number of pages to print: ";
    cin >> pages;
    double cost = pages * pricing["Print"];
    cout << "Printed " << pages << " pages. Total cost: $" << cost << endl;
}

// Scan documents
void scanDocuments() {
    int pages;
    cout << "Enter number of pages to scan: ";
    cin >> pages;
    double cost = pages * pricing["Scan"];
    cout << "Scanned " << pages << " pages. Total cost: $" << cost << endl;
}


void userMenu() {
    int choice;
    do {
        cout << "\n--- User Menu ---" << endl;
        cout << "1. Print Documents" << endl;
        cout << "2. Scan Documents" << endl;
        cout << "3. Logout" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: printDocuments(); break;
        case 2: scanDocuments(); break;
        case 3: cout << "Logging out..." << endl; break;
        default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);
}

// Admin Menu
void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Dashboard ---" << endl;
        cout << "1. Show Active Users" << endl;
        cout << "2. Inactivate User" << endl;
        cout << "3. Update Pricing" << endl;
        cout << "4. Print Documents" << endl;
        cout << "5. Scan Documents" << endl;
        cout << "6. Logout" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: showActiveUsers(); break;
        case 2: deleteUser(); break;
        case 3: updatePricing(); break;
        case 4: printDocuments(); break;
        case 5: scanDocuments(); break;
        case 6: cout << "Logging out..." << endl; break;
        default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);
}


int main() {
    int choice;
    do {
        cout << "\n--- Skyline Cyber Café Billing System ---" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: registerUser(); break;
        case 2: {
            string email;
            int userIndex = login(email);
            if (userIndex != -1) {
                if (users[userIndex].isAdmin) {
                    cout << "\nWelcome Admin: " << users[userIndex].name << endl;
                    adminMenu();
                }
                else {
                    cout << "\nWelcome User: " << users[userIndex].name << endl;
                    userMenu();
                }
            }
            else {
                cout << "Invalid login or user not active." << endl;
            }
            break;
        }
        case 3: cout << "Exiting system. Thank you!" << endl; break;
        default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
