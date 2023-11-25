#pragma once
#include <iostream>
#include <string>
using namespace std;

class Util1 {
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}
	static char* genRandom()
	{
		static const char alphanum[] =
			"0123456789"
			"!@#$%^&*"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

		int stringLength = sizeof(alphanum) - 1;
		char* id = new char[9];
		srand(time(NULL));
		for (unsigned int i = 0; i < 8; ++i)
		{
			id[i] += alphanum[rand() % stringLength];

		}
		return id;
	}
};

class Location {
private:
	char* tableId;
	char* name;
	char* address;
	int noTables = 0;
	int noChairs = 0;
	int noVipTables = 0;

public:

	char* getName() {
		return this->name;
	}

	char* getAddress() {
		return this->address;
	}

	int getNoTables() {
		return this->noTables;
	}

	int getNoChairs() {
		return this->noChairs;
	}

	int getNoVipTables() {
		return this->noVipTables;
	}

	char* getTableId() {
		return this->tableId;
	}
	void setName(const char* newName) {
		//validate input

		if (newName[0] < 'A' || newName[0] > 'Z') {
			throw exception("First letter is not capital letter");
		}

		this->name = Util1::copyString(newName);
	}
	void setAddress(const char* eventAddress) {
		if (eventAddress)
			this->address = Util1::copyString(eventAddress);
	}

	void setNoTables(int noTablesEvent) {
		this->noTables = noTablesEvent;
	}
	void setNoChairs(int noChairsEvent) {
		this->noChairs = noChairsEvent;
	}

	void setnoVipTables(int noVipTablesEvent) {
		this->noVipTables = noVipTablesEvent;
	}

	void setTableId() {
		this->tableId = Util1::genRandom();
	}

	Location() {
		this->setName("The place");
		this->setAddress("Liberty Street");
		this->setNoTables(20);
		this->setnoVipTables(5);
		this->setNoChairs(100);
	}

	Location(char* name, char* address, int noTables, int noVipTables, int noChairs) {
		this->setName(name);
		this->setAddress(address);
		this->setNoTables(noTables);
		this->setnoVipTables(noVipTables);
		this->setNoChairs(noChairs);
	}



	friend ostream& operator<<(ostream& console, const Location& loc);

};
//std::ostream& operator<<(std::ostream& console, const Location& loc) {

ostream& operator<<(ostream& console, const Location& loc) {
	console << endl << "loc name: " << loc.name;
	console << endl << "loc price: " << loc.address;
	console << endl << "Current month: " << loc.noTables;
	console << endl << "Current month: " << loc.noChairs;
	console << endl << "Current month: " << loc.noVipTables;

	return console;
}


