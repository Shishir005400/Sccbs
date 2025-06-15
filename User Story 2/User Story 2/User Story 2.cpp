// User Story 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

struct User {
	string name;
	string email;
	string password;
	bool isAdmin;
	bool isActive;
};

vector<User> users;

bool validatePassword(string input) {
	regex pattern("^(?=.*[A-Z])(?=.*\\d).{8,}$");
	return regex_match(input, pattern);
}
void registerUser() {
	User user;
	cout << "Enter name: ";
	cin >> user.name;
	cout << "Enter email: ";
	cin >> user.email;
	do {
		cout << "Enter strong password (min 8 chars, 1 uppercase, 1 digit): ";
		cin >> user.password;
		if (!validatePassword(user.password)) {
			cout << "Invalid password. Try again.\n";
		}
	} while (!validatePassword(user.password));
	user.isAdmin = false;
	user.isActive = true;
	users.push_back(user);
	cout << "Registration Successfully!\n";
}
int main() {
	registerUser();
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
