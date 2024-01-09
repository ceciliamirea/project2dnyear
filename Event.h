#pragma once
#include <string>
#include <iostream>
#include "Location.h"
#include "Util.h"
using namespace std;


class Event {
private:
	const string name;
	char date[11] = ""; //dd/mm/yyyy
	string bands[20];
	string sponsors[20];

public:

	string getName() {
		return this->name;
	}

	char* getDate() {
		return this->date;
	}

	string getSpecificBand(int index) {
		return this->bands[index];
	}

	string getSpecificSponsor(int index) {
		return this->sponsors[index];
	}

	void setBands(string bands[], int noBands) {
		if (noBands > 20) throw exception("Too many bands (20 max)");
		for (int i = 0; i < noBands; i++) {
			this->bands[i] = bands[i];
		}
	}


	void setSponsors(string sponsors[], int noSponsors) {

		if (noSponsors > 20) throw exception("Too many sponsors (20 max)");
		for (int i = 0; i < noSponsors; i++) {
			this->sponsors[i] = sponsors[i];
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


	Event() : name("Alternative Night")
	{
		string sponsors[] = { "Rock FM", "IaBilet" , "Motoland" };
		string bands[] = { "Alternosfera", "Byron", "The Mono Jacks" };
		this->setDate("15/12/2023");
		this->setBands(bands, sizeof(bands) / sizeof(bands[0]));
		this->setSponsors(sponsors, sizeof(sponsors) / sizeof(sponsors[0]));
	}
	Event(const string name, char* date, string bands[], string sponsors[]) :name(name) {

		this->setDate(date);
		this->setBands(bands, sizeof(bands) / sizeof(bands[0]));
		this->setSponsors(sponsors, sizeof(sponsors) / sizeof(sponsors[0]));
	}

	bool operator==(Event ev) {
		if (this->name == ev.name) {
			return true;
		}
		else return false;

	}

	bool operator>(Event ev) {
		if (this->date[0] + this->date[1] < ev.date[0] + ev.date[1] && this->date[3] + this->date[4] < ev.date[3] + ev.date[4]) {
			return false;
		}
		else if (this->date[3] + this->date[4] < ev.date[3] + ev.date[4])
			return false;

		else
			return true;
	}


	void cancelBand(string aBand) {
		bool found = false;
		int i, j;

		for (i = 0; i < sizeof(this->bands) / sizeof(this->bands[0]); i++) {
			if (aBand.compare(this->bands[i]) == 0) {
				found = true;

				for (j = i; j < sizeof(this->bands) / sizeof(this->bands[0]) - 1; j++) {

					this->bands[j] = this->bands[j + 1];

				}
			}
		}

		if (found == false) {
			throw exception("Wrong band.");
		}
	}

	void cancelSponsor(string aSponsor) {
		bool found = false;
		int i, j;
		for (i = 0; i < sizeof(this->sponsors) / sizeof(this->sponsors[0]); i++) {
			if (aSponsor.compare(this->sponsors[i]) == 0) {
				found = true;

				for (j = i; j < sizeof(this->sponsors) / sizeof(this->sponsors[0]) - 1; j++) {

					this->sponsors[j] = this->sponsors[j + 1];

				}
			}
		}

		if (found == false) {
			throw exception("Wrong sponsor.");
		}
	}



	string& operator[](int index) {
		if (index > sizeof(this->bands) / sizeof(this->bands[0]) || index < 0) {
			throw exception("Wrong index");
		}
		return this->bands[index];
	}

	//destructor
	~Event() {
	}

	friend void operator<<(ostream& console, Event& e);
	friend void operator>> (istream& is, Event& e);

};
void operator>>(istream& is, Event& e) {
	cout << endl << "Date: ";
	is >> e.date;
	cout << endl << "Bands (write 0 if you want to stop): ";
	string i = "";
	int index = 0;
	while (i.compare("0") != 0) {
		is >> i;
		if (i.compare("0") != 0)
			e.bands[index] = i;
		index++;
	}
	cout << endl << "Sponsors (write 0 if you want to stop): ";
	index = 0; i = "";
	while (i.compare("0") != 0) {
		is >> i;
		if (i.compare("0") != 0)
			e.sponsors[index] = i;
		index++;


	}

}
void operator<<(ostream& console, Event& e) {
	console << endl << "Name: " << e.name;
	console << endl << "Date: " << e.date;
	console << endl << "Current Bands: ";
	for (int i = 0; i < sizeof(e.bands) / sizeof(e.bands[0]); i++) {
		if (e.bands[i].compare("") != 0) {
			cout << e.bands[i] << " , ";
		}

	}
	console << endl << "Current Sponsors: ";
	for (int i = 0; i < sizeof(e.sponsors) / sizeof(e.sponsors[0]); i++) {
		if (e.sponsors[i].compare("") != 0) {
			cout << e.sponsors[i] << " , ";
		}
	}


}