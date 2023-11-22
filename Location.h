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

	char* getAdress() {
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

	void setAdress(const char* eventAddress) {
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
	
};

