// For admin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
	string name;
	string email;
	string password;
	bool isAdmin;
	bool isActive;
};
vector<User>users =
{
	{"Admin","admin@sys.com","Admin123",true,true},
	{"UserOne","user1@example.com","User1234",false,true},
	{"UserTwo","user2@example.com","User5678",false,true}
};
void deleteUser()
{
	string targetEmail;
	cout << "Enter the email of the user to inactive :" << endl;
	cin >> targetEmail;
	bool found = false;
	for (auto& user : users) {
		if (user.email == targetEmail && user.isActive) {
			user.isActive = false;
			cout << "User" << user.email << "Has been inactived" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "User not found or already inactive" << endl;
	}
}
void showActiveUser() {
	cout << "Active users" << endl;
	for (const auto& user : users) {
		if (user.isActive) {
			cout << "_" << user.email << endl;
		}
	}
}
int main() {
	showActiveUser();
	deleteUser();
	showActiveUser();
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
