#pragma once
#include <string>
#include <location.h>

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

class Event {
private:
	int eventID=0;
	const string name;
	char date[11] = ""; //dd/mm/yyyy
	char* bands[10];
	Location* locationEvent = nullptr;
	char* sponsors[20];

	static int TOTAL_EVENTS;


public:

	string getName() {
		return this->name;
	}

	char* getDate() {
		return Util::copyString(this->date);
	}

	char* getBands() {
		return Util::copyString(this->bands);
	}

	char* getSponsors() {
		return Util::copyString(this->sponsors);
	}

	//Location* getLocationEvent() {
		//return Util::copyString(this->locationEvent);}

	

	void setName(string newName) {
		//validate input
		
		if (newName[0] < 'A' || newName[0] > 'Z') {
			throw exception("First letter is not capital letter");
		}

		this->name = newName;
	}

	void setBands(const char* panelBands) {
		this->bands = Util::copyString(panelBands);
	}

	void setLocation(Location* location)
	{
		if (location != locationEvent) {
			throw exception("Wrong location");
	    }
	}

	void setSponsors(char* sponsorsEvent) {
		this->sponsors = Util::copyString(sponsorsEvent);
	}

	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("Wrong date");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("Wrong date format");
		}

		strcpy_s(this->date, newDate);
	}

};