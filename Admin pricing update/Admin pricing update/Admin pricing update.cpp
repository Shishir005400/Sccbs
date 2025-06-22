// Admin pricing update.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, double> pricing = {
	{"Print", 0.20},
	{"Scan", 0.10}
};

void updatePricing()
{
	string service;
	double newPrice;
	cout << "Enter service to update(Print/Scan):" << endl;
	cin >> service;

	if (pricing.find(service) != pricing.end())
	{
		cout << "Current Price : $" << pricing[service] << endl;
		cout << "Enter New Price :$" << endl;
		cin >> newPrice;
		pricing[service] = newPrice;
		cout << service << "Price Update to $ :" << newPrice << endl;
	}
	else
	{
		cout << "Invalid service name" << endl;
	}
}
int main()
{
	updatePricing();
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
