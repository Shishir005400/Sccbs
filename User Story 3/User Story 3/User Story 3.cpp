// User Story 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream >
#include <unordered_map>
using namespace std;

unordered_map<string, double> pricing = { {"Print", 0.10}, {"scan", 0.05} };
void scanDocuments() {
	int pages;
	cout << "Enter number of pages to scan: ";
	cin >> pages;
	double cost = pages * pricing["scan"];
	cout << "scanned" << pages << "pages. Total cost: $" << cost << endl;
}
void printDocuments() {
	int pages;
	cout << "Enter number of pages to print: ";
	cin >> pages;
	double cost = pages * pricing["print"];
	cout << "Printed" << pages << "pages, Total cost: $" << cost << endl;
}
int main() {
	int choice;
	do {
		cout << "\n--- Print & Scan Billing ---\n";
		cout << "1. Print Documents\n 2. Scan Documents\n 3. Exit\nChoice: ";
		cin >> choice;

		if (choice == 1) {
			printDocuments();
		}
		else if (choice == 2) {
			scanDocuments();
		}
	} while (choice != 3);
	cout << "Thank you for using the Print & Scan Billing System!" << endl;
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
