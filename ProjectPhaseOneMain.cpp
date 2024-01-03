#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
using namespace std;

int main()
{
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
	using namespace std;

	//menu for a customer

	void MenuChoiceUser1() {
		int choice;

		cout << "Choose an option: " << endl;
		cout << "1. Check disponibility " << endl;
		cout << "2. Buy ticket" << endl;
		cout << "3. Book a table " << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: " << endl;

		cin >> choice;

		while (choice < 1 || choice > 5) {
			cout << "Try again and choose one of the options." << endl;
			cin >> choice;
		}

		if (choice == 1) {

			Location locat;
			cout << locat.checkDisponibility() << endl;
		}

		if (choice == 2) {
			Ticket t;
			Location l;
			int whichType = 0;
			cout << "The price for a regular table is: " << t.getPrice() << endl;
			cout << "The price for a VIP table is: " << t.getVipPrice() << endl;
			cout << "Which one would you like?: " << endl << "1. Regular " << endl << "2. VIP " << endl;
			cin >> whichType;
			while (whichType != 1 && whichType != 2) {
				cout << "Please choose one of the two options.";
				cin >> whichType;
			}

			if (whichType == 1) {
				l.ticketPurchased();
			}

			if (whichType == 2) {
				l.VIPticketPurchased();
			}
			cout << "Thank you. Here is your ticket" << endl << t.getTicketID();

		}

		if (choice == 3) {
			Ticket tick;
			Location l;
			tick.bookTable(l);
		}

		if (choice == 4) {
			int exit;
			cout << "Press 1 to exit" << endl;
			cin >> exit;
		}

	}
	//menu for an administrator
	void MenuChoiceUser2() {

		int choice;

		cout << "Choose an option: " << endl;
		cout << "1. Modify location info " << endl;
		cout << "2. Modify ticket info" << endl;
		cout << "3. Modify event " << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: " << endl;

		cin >> choice;

		while (choice < 1 || choice > 5) {
			cout << "Try again and choose one of the options." << endl;
			cin >> choice;
		}

		if (choice == 1) {
			Location loc;
			string newname;
			string address;
			int notables;
			int noviptables;
			cout << "Modify the location's name" << endl;
			loc.setName(newname);
			cout << "Change the address of the event" << endl;
			loc.setAddress(address);
			cout << "Change the number of regular tables" << endl;
			loc.setNoTables(notables);
			cout << "Change the number of VIP tables" << endl;
			loc.setnoVipTables(noviptables);

		}
		if (choice == 2) {
			Ticket tic;
			int price;
			int vipprice;
			cout << "Change the price" << endl;
			tic.setPrice(price);
			cout << "Change the VIP price" << endl;
			tic.setVipPrice(vipprice);

		}

		if (choice == 3) {
			Event ev;
			string bands[20];
			int nobands;
			cout << "Change the bands" << endl;
		}



	}

	int main()
	{
		Location location;
		cout << location;
		cout << endl;
		cout << location.getAddress() << endl;
		cout << location.getName() << endl;
		cout << location.getNoTables();
		cout << endl;

		location.setName("Bucuresti");
		cout << location;

		Location loc("Ct", "Adr", 15, 4);
		cout << loc;

		Location ceva = ++loc;
		cout << ceva;

		Ticket ticket;
		cout << ticket;
		cout << endl;
		cout << ticket.getPrice() << endl;
		cout << ticket.getTicketID() << endl;

		Event event;
		cout << event;
		cout << endl;
		cout << event.getName() << endl;
		cout << event.getSpecificBand(1) << endl;
		event.setDate("27/08/2024");
		cout << event;

	}

	cout << location;
	cout << endl;
	cout << location.getAddress() << endl;
	cout << location.getName() << endl;
	cout << location.getNoTables();
	cout << endl;

	location.setName("Bucuresti");
	cout << location;

	Location loc("Ct", "Adr", 15, 4);
	cout << loc;

	Location ceva = ++loc;
	cout << ceva;

	Ticket ticket;
	cout << ticket;
	cout << endl;
	cout << ticket.getPrice() << endl;
	cout << ticket.getTicketID() << endl;

	Event event;
	cout << event;
	cout << endl;
	cout << event.getName() << endl;
	cout << event.getSpecificBand(1) << endl;
	event.setDate("27/08/2024");
	cout << event;

}

