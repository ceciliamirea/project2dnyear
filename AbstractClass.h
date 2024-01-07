#pragma once
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
using namespace std;


class AbstractClass {
	bool discounted = false;
	int discount = 0;

public:
	virtual void showMsj() = 0;
	bool getChoice() {
		return this->discounted;
	}
	int getiDscount() {
		return this->discount;
	}
	void setChoice() {
		int choice;
		cout << "Do you have a discount? Please select:" << endl << "1.Discounted Ticket" << endl << "2.Full priced ticket" << endl;
		cin >> choice;

		if (choice == 1) {
			this->discounted = true;
		}
		else this->discounted = false;
	}
	void setDiscount(int disc) {
		this->discount = disc;
	}

};

class Derivated : AbstractClass {
	int discount = 0;
	DiscountedTicket t;
public:


	void showMsj() {
		setChoice();
		bool choice = getChoice();

		if (choice == true) {
			cout << "Please write the discount ( 1-100 ) :";
			cin >> this->discount;
			setDiscount(this->discount);
			t.setDiscount(this->discount);
			cout << "Now the price is :" << t.getDiscount() << endl;
			cout << "Which one would you like?: " << endl << "1. Regular " << endl << "2. VIP " << endl;
		}
		else {
			cout << "Which one would you like?: " << endl << "1. Regular " << endl << "2. VIP " << endl;
		}

	}
};
