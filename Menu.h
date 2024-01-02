#pragma once
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
using namespace std;

class Menu {
public:

	void MenuChoice() {
		int choice = 0;

		if (choice >= 1 && choice <= 4) {
			cout << "Choose an option: " << endl;
			cout << "1. Check disponibility " << endl;
			cout << "2. Buy ticket" << endl;
			cout << "3. Modify Event" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choice: " << endl;
			cin >> choice;
		}
		else cout << "Try again and choose one of the options." << endl;


	}
};