#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
using namespace std;
time_t timestamp;


int main() {
	map<string, double> income;
	map<string, double> expenses;
	char select, select2;
	string name, incName, expName, date, fileName;
	double incValue, expValue;

	cout << "===== Financial Tracker =====" << endl;
	cout << "Input Username: ";
	getline(cin, name);
	cout << "Input Date (dd/mm/yy): ";
	cin.ignore();
	getline(cin, date);
	cout << "\nWelcome, " << name << "! " << "What Would you like to do? " << endl;

	do {
		cout << "\n[A] Add Income\n" << "[B] Add Expense\n" << "[C] Generate Report\n" << "[D] Exit\n" << endl;
		cout << "Enter Option Here: ";
		cin >> select;
		cin.ignore();

		switch (select) {
		case 'a':;
		case 'A':
			cout << "Add Income\n";
			cout << "Income source: ";
			getline(cin, incName);
			cout << "Input amount: ";
			cin >> incValue;
			income[incName] = incValue;
			cout << "Income added.\n";
			break;

		case 'b':
		case 'B':
			cout << "Add an Expense\n";
			cout << "Expense name: ";
			cin.ignore();
			getline(cin, expName);
			cout << "Input amount: ";
			cin >> expValue;
			expenses[expName] = expValue;
			cout << "Expense added.\n";
			break;

		case 'c':
		case 'C':
			cout << "Financial Report";

			cout << "Would you like to save this report? Y/N\nInput: ";
			cin >> select2;

			if (select2 == 'Y' || select2 == 'y')
			{
				cout << "Input File name: ";
				cin.ignore();
				getline(cin, fileName);
				fileName = fileName + "(" + date + ").txt";

				ofstream report(fileName);
				if (report.is_open()) {
					report << "===== Income Report =====\n";
					for (const auto& item : income) {
						report << item.first << ": " << item.second << endl;
					}

					report << "\n===== Expense Report =====\n";
					for (const auto& item : expenses) {
						report << item.first << ": " << item.second << endl;
					}

					report.close();
					cout << "\nReport generated and saved as '" << fileName << "'\n";
				}
				else {
					cout << "\nError opening file to save the report.\n";
				}
			}
			else if (select2 == 'N' || select2 == 'n')
				cout << "File not saved.";
			break;

		case 'd':
		case 'D':
			cout << "\nTerminating program...";
			break;
		default: cout << "Invalid Input. Please use a letter from the selection.";
		}
	} while (select != 'd' && select != 'D');

	return 0;
}