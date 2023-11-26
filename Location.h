#pragma once
#include <iostream>
#include <string>
#include "Util.h"

using namespace std;


class Location {
private:
	char* tableId;
	char* name;
	char* address;
	int noTables = 0;
	int noVipTables = 0;

	static	int TOTAL_CHAIRS;


public:

	static int getTotalNoChairs() {
		return Location::TOTAL_CHAIRS;
	}

	char* getName() {
		return this->name;
	}


	char* getAddress() {
		return this->address;
	}

	int getNoTables() {
		return this->noTables;
	}

	int getNoVipTables() {
		return this->noVipTables;
	}

	char* getTableId() {
		return this->tableId;
	}
	void setName(string newName) {
		delete[] this->name;

		if (newName[0] < 'A' || newName[0] > 'Z') {
			throw exception("First letter is not capital letter");
		}

		this->name = Util::copyString(newName.c_str());
	}
	void setAddress(string eventAddress) {
		delete[] this->address;

		this->address = Util::copyString(eventAddress.c_str());
	}

	void setNoTables(int noTablesEvent) {
		if (noTablesEvent <= this->noVipTables) throw exception("Wrong number of tables.");
		this->noTables = noTablesEvent;
	}


	void setnoVipTables(int noVipTablesEvent) {
		if (noVipTablesEvent >= this->noTables) throw exception("Wrong number of tables.");
		this->noVipTables = noVipTablesEvent;
	}

	void setTableId() {
		delete[] this->tableId;
		this->tableId = Util::copyString(Util::printstring(8).c_str());
	}

	Location() {
		this->setName("The place");
		this->setAddress("Liberty Street");
		this->setNoTables(20);
		this->setnoVipTables(5);
		Location::TOTAL_CHAIRS = this->noTables * 4 + this->noVipTables * 4;
	}

	Location(string name, string address, int noTables, int noVipTables) {
		this->setName(name);
		this->setAddress(address);
		this->setNoTables(noTables);
		this->setnoVipTables(noVipTables);
		Location::TOTAL_CHAIRS = noTables * 4 + noVipTables * 4;
	}


	//postfix version
	Location operator++(int) {
		Location copy = *this;
		this->noTables += 5;
		return copy;
	}

	//prefix version
	Location operator++() {
		this->noTables += 5;
		return *this;
	}

	bool operator==(Location l) {
		if (l.noTables == this->noTables) {
			return true;
		}
		else return false;
	}

	void ticketPurchased() {
		this->noTables -= 1;
	}

	bool checkDisponibility() {
		if (this->noTables != 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//destructor
	~Location() {
		delete[] this->tableId;
	}

	friend void operator<<(ostream& console, Location& loc);

	friend void operator>> (istream& is, Location& loc);

};

int Location::TOTAL_CHAIRS = 0;
void operator>>(istream& is, Location& loc) {
	cout << endl << "Location name: ";
	is >> loc.name;
	cout << endl << "Location address: ";
	is >> loc.address;
	cout << endl << "Number of current tables: ";
	is >> loc.noTables;
	cout << endl << "Number of current Vip tables: ";
	is >> loc.noVipTables;

}

void operator<<(ostream& console, Location& loc) {
	console << endl << "Location name: " << loc.name;
	console << endl << "Location address: " << loc.address;
	console << endl << "Number of current tables: " << loc.noTables;
	console << endl << "Number of current chairs: " << loc.TOTAL_CHAIRS;
	console << endl << "Number of current Vip tables: " << loc.noVipTables;

}



