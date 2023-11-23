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

	void setBands(const char* panelBands, int noBands) {
		
		for (int i = 0; i < noBands; i++) {
			if (panelBands[i] == "") {
				throw exception("Wrong number of bands.");
			}
			this->bands[i] = panelBands[i];
		}
	}

	void setLocation(Location* location)
	{
		if (location != locationEvent) {
			throw exception("Wrong location");
	    }

		this->location = locationEvent;
	}

	void setSponsors(char* sponsorsEvent, int noSponsors) {

		for (int i = 0; i < noSponsors; i++) {
			if (sponsorsEvent[i] == "") {
				throw exception("Wrong number of sponsors");
			}
			this->sponsors[i] = sponsorsEvent[i];
		}
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

	string* getRoadmap() {
		string* copy = new string[this->noLocations];
		for (int i = 0; i < this->noLocations; i++) {
			copy[i] = this->roadmap[i];
		}
		return copy;
	}

	//void setRoadmap(string* newRoadmap, int noLocations) {
	//	//shallow copy
	//	//this->roadmap = newRoadmap;

	//	//deep copy
	//	this->roadmap = new string[noLocations];
	//	for (int i = 0; i < noLocations; i++) {
	//		this->roadmap[i] = newRoadmap[i];
	//	}
	//	this->noLocations = noLocations;
	//}

	Event() {
		this->setName("Alternative Night");
		this->setDate("15/12/2023");
		this->setLocation("The Place");
		this->setBands({ "Alternosfera", "The Mono Jacks", "Byron", "Dirty Shirt" },4);
		this->setSponsors({ "Rock FM", "IaBilet", "Motoland" },3);
	}
	Event(const string name, char date, char* bands, char* sponsors, Location locationEvent, int noBands, int noSponsors) {

		this->setName(name);
		this->setDate(date);
		this->setBands(bands,noBands);
		this->setLocation(locationEvent);
		this->setSponsors(sponsors, noSponsors);
	}
};