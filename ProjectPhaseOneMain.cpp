#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
#include "AbstractClass.h"
using namespace std;

//menu for a customer

void MenuChoiceUser1() {
	int choice;
	Location l;

	cout << "Choose an option: " << endl;
	cout << "1. Check disponibility " << endl;
	cout << "2. Buy ticket" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice: " << endl;

	cin >> choice;
	while (choice != 3) {

		while (choice < 1 || choice > 3) {
			cout << "Try again and choose one of the options." << endl;
			cin >> choice;
		}

		if (choice == 1) {

			//Location locat;
			//cout << locat.checkDisponibility() << endl;
			bool check = l.checkDisponibility();
			if (check == 1) {
				cout << "There are " << l.getNoTables() << " available regular tables and " << l.getNoVipTables() << " available VIP tables." << endl;
			}
			else cout << "There are not available tables." << endl;

		}

		if (choice == 2) {
			Ticket t;
			//Location l;
			DiscountedTicket dt;
			int whichType = 0;
			cout << endl << "The price for a regular table is: " << t.getPrice() << endl;
			cout << "The price for a VIP table is: " << t.getVipPrice() << endl;

			Derivated d;

			d.showMsj();
			//cout << "Which one would you like?: " << endl << "1. Regular " << endl << "2. VIP " << endl;
			cin >> whichType;
			while (whichType != 1 && whichType != 2) {
				cout << "Please choose one of the two options." << endl;
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

		cout << endl << "Choose an option: " << endl;
		cout << "1. Check disponibility " << endl;
		cout << "2. Buy ticket" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
	}
}
//menu for an administrator
void MenuChoiceUser2() {

	int choice;
	cout << "Choose an option: " << endl;
	cout << "1. Modify location info " << endl;
	cout << "2. Modify ticket info" << endl;
	cout << "3. Modify event " << endl;
	cout << "4. Show info " << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: " << endl;

	cin >> choice;
	while (choice != 5) {

		while (choice < 1 || choice > 6) {
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
			cin >> newname;
			loc.setName(newname);
			cout << "Change the address of the event" << endl;
			cin >> address;
			loc.setAddress(address);
			cout << "Change the number of regular tables" << endl;
			cin >> notables;
			loc.setNoTables(notables);
			cout << "Change the number of VIP tables" << endl;
			cin >> noviptables;
			loc.setnoVipTables(noviptables);

		}
		if (choice == 2) {
			Ticket tic;
			int price;
			int vipprice;
			cout << "Change the price" << endl;
			cin >> price;
			tic.setPrice(price);
			cout << "Change the VIP price" << endl;
			cin >> vipprice;
			tic.setVipPrice(vipprice);

		}

		if (choice == 3) {
			Event ev;
			string bands[20];
			string stop = "1";
			string band;
			int nrBands = 0;
			int nrSponsors = 0;
			string sponsors[30];
			string sponsor;

			cout << "Write the bands :" << endl;

			while (stop != "0" && nrBands < 21) {
				cout << "Band no " << nrBands << " :";
				cin >> band;
				bands[nrBands] = band;
				nrBands++;
				cout << "If you want to stop, press 0  ";
				cin >> stop;
			}

			ev.setBands(bands, nrBands);

			cout << "Write the sponsors :" << endl;

			while (stop != "1" && nrBands < 31) {
				cout << "Sponsor no " << nrSponsors << " :";
				cin >> sponsor;
				sponsors[nrSponsors] = sponsor;
				nrSponsors++;
				cout << "If you want to stop, press 1  ";
				cin >> stop;
			}

			ev.setSponsors(sponsors, nrSponsors);

			cout << ev;

			cout << endl << "Change the date" << endl;
			char* day = new char[3];
			char* month = new char[3];
			char* year = new char[5];
			char* date = new char[11];

			cout << "Enter the Day-> "; cin >> day;
			cout << "Enter the Month-> "; cin >> month;
			cout << "Enter the Year-> "; cin >> year;

			strcat_s(day, 4, "/");
			strcat_s(day, 6, month);
			strcat_s(day, 8, "/");
			strcat_s(day, 11, year);
			strcpy_s(date, 11, day);

			ev.setDate(date);
			cout << ev;

			string deletedband;
			cout << "If a band canceled, delete band" << endl;
			cout << "Type the band's name: ";
			cin >> deletedband;

			ev.cancelBand(deletedband);

			cout << "Band deleted successfully." << endl;

			string deletesponsor;
			cout << "If a sponsor canceled, delete sponsor" << endl;
			cout << "Type the sponsor's name: ";
			cin >> deletesponsor;

			ev.cancelSponsor(deletesponsor);

			cout << "Sponsor deleted successfully." << endl;

		}
		if (choice == 4) {
			int choiceforclass;
			cout << "Show info for Location-> 1" << endl;
			cout << "Show info for Ticket-> 2" << endl;
			cout << "Show info for Event-> 3" << endl;
			cin >> choiceforclass;

			while (choiceforclass < 1 || choiceforclass > 3) {
				cout << "Try again and choose one of the options." << endl;
				cin >> choiceforclass;
			}

			if (choiceforclass == 1) {
				Location loc;
				cout << loc;
				cout << endl;
				cout << loc.getAddress() << endl;
				cout << loc.getName() << endl;
				cout << loc.getNoTables() << endl;
				cout << endl;

			}

			if (choiceforclass == 2) {
				Ticket tick;
				cout << tick;
				cout << endl;
				cout << tick.getPrice() << endl;
				cout << tick.getVipPrice() << endl;
				cout << endl;

			}

			if (choiceforclass == 3) {
				Event ev;
				cout << ev;
				cout << endl;
				//ev.setDate("21/02/2024");
				//cout << ev.setBands() << endl;
				cout << ev.getSpecificSponsor(1) << endl;
				cout << endl;

			}

		}

		cout << "Choose an option: " << endl;
		cout << "1. Modify location info " << endl;
		cout << "2. Modify ticket info" << endl;
		cout << "3. Modify event " << endl;
		cout << "4. Show info " << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: " << endl;

		cin >> choice;

	}


}

int main()
{
	/*Location location;
	cout << location;
	cout << endl;
	cout<< location.getAddress() << endl;
	cout<< location.getName() << endl;
	cout<< location.getNoTables();
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
	cout << ticket.getPrice()<<endl;
	cout << ticket.getTicketID()<<endl;

	Event event;
	cout << event;
	cout<<endl;
	cout << event.getName() << endl;
	cout << event.getSpecificBand(1) << endl;
	event.setDate("27/08/2024");
	cout << event;*/
	int usertype;
	cout << "Are you  a customer or an administrator?" << endl << "Press 1 for customer or press 2 for administrator" << endl;
	cin >> usertype;
	while (usertype < 1 || usertype > 2) {
		cout << "Try again and choose one of the options." << endl;
		cin >> usertype;
	}
	if (usertype == 1) {
		MenuChoiceUser1();

	}
	if (usertype == 2) {


		MenuChoiceUser2();
	}
}

