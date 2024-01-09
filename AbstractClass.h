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
	virtual void setChoice() {
		int choice;
		cout << "Do you have a discount? Please select:" << endl << "1.Discounted Ticket" << endl << "2.Full priced ticket" << endl;
		cin >> choice;

		if (choice == 1) {
			this->discounted = true;
		}
		else this->discounted = false;
	}

	virtual bool setCoupon() {
		return false;

	}

	virtual bool verifyAt() {
		return false;
	}

	void setDiscount(int disc) {
		this->discount = disc;
	}

};

class Derivated : AbstractClass {
	int discount = 0;
	DiscountedTicket t;
public:

	bool verifyAt() {
		int choice;
		cout << "Have you been here?" << endl << "1.Yes" << endl << "2.No" << endl;
		cin >> choice;

		if (choice == 1) {
			return true;
		}
		else return false;
	}

	bool setCoupon() {
		int code = 1234;
		int value;
		cout << "Please enter your discount code: (for testing enter 1234) " << endl;
		cin >> value;
		while (value != code) {
			cout << "Wrong code. " << endl;
			return false;
		}
		cout << "Code accepted." << endl;
		return true;
	}


	void showMsj() {
		setChoice();
		bool choice = getChoice();

		///////////

		if (choice == true && setCoupon()) {
			cout << "Please write the discount ( 1-50 ) :";
			cin >> this->discount;
			while (this->discount > 50) {
				cout << "Wrong value." << endl;
				cin >> this->discount;
			}
			if (verifyAt()) {
				this->discount = this->discount + 10;
			}
			setDiscount(this->discount);
			t.setDiscount(this->discount);
			cout << "Now the price is :" << t.getDiscount() << endl;
			cout << "Which one would you like?: " << endl << "1. Regular " << endl;

		}
		else {
			cout << "Which one would you like?: " << endl << "1. Regular " << endl << "2. VIP " << endl;
		}

	}
};
