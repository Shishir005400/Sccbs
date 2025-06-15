// User Story 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	regex pattern("^(?=.*[A-Z])(?=.*\\D).{8,}$");
	return regex_match(input, pattern);
}
bool validateEmail(string input) {
	regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
	return regex_match(input, pattern);
}
void registerUser() {
	User user;
	cout << "Enter name: ";
	cin >> user.name;
	if (user.name.empty()) {
		cout << "Name cannot be empty" << endl;
		return;
	}
	do {
		cout << "Enter email: ";
		cin >> user.email;
		if (!validateEmail(user.email)) {
			cout << "Invalid email format" << endl;
		}
	} while (!validateEmail(user.email));
	do {
		cout << "Enter strong password ( min 8 chars, 1 upppercase, 1 digit):";
		cin >> user.password;
		if (!validatePassword(user.password)) {
			cout << "Invalid password. Try again.\n";
		}
	} while (!validatePassword(user.password));
	user.isAdmin = false;
	user.isActive = true;
	users.push_back(user);
	cout << "Registration successfully!\n";
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
