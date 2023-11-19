#pragma once
#include <string>
#include <location.h>
#include <sponsors.h>

class Event {
private:
	const string name;
	char date[11] = "";
	char* bands[10];
	Location* locationEvent = nullptr;
	char* sponsors[20];

	static int TOTAL_EVENTS;

	//The setters: 

	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("Wrong date");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("Wrong date format");
		}

		strcpy_s(this->date, newDate);
	}
	
	void setBands(char* bands);
	void setLocation(Location* locationEvent);
	void setSponsors(char* sponsors);
	//void setDate(const char date);

public:

	string getName() {
		return this->name;
	}
	

};