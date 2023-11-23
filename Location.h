#pragma once
#include <iostream>
#include <string>

class Util {
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}
};

class Location {
private:
	char* name[10];
	char* address[25];
	//Event** events = nullptr;
	int noTables=0;
	int noChairs=0;
	int noVipTables=0;

public:
	
	char* getName() {
		return this->name;
	}

	char* getAddress() {
		return this->Util::copyString(address);
	}

	int getNoTables() {
		return this->noTables;
	}

	int getNoChairs() {
		return this->noChairs;
	}

	int getNoVipTables() {
		return this->getNoVipTables;
	}

	void setName(string newName) {
		//validate input

		if (newName[0] < 'A' || newName[0] > 'Z') {
			throw exception("First letter is not capital letter");
		}

		this->name = newName;
	}
	void setAddress(const char* eventAddress) {
		this->address = Util::copyString(eventAddress);
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
	
	Location() {
		this->setName("The place");
		this->setAddress( "Liberty Street number 5" );
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

};


