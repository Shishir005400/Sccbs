// Userstory 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User
{
	string name;
	string email;
	string password;
	bool isAdmin;
	bool isActive;
};
vector<User>users =
{
	{"Admin","admin@sys.com","Admin123",true,true}
};
int login(string& email)
{
	string password;
	cout << "Enter Email:";
	cin >> email;
	cout << "Enter Password:";
	cin >> password;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].email == email && users[i].password == password && users[i].isActive) {
			return i;
		}
	}
	return -1;
}
int main()
{
	string currentEmail;
	int userIndex = login(currentEmail);
	if (userIndex != -1 && users[userIndex].isAdmin)
	{
		cout << "Welcome to the Admin Dashboard," << users[userIndex].name << endl;
	}
	else
	{
		cout << "Invalid login or user not active" << endl;
	}
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
