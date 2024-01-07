#pragma once
#include <iostream>
#include <string>
#include "Util.h"
#include "Location.h"

using namespace std;


class Ticket {
private:

	char* ticketID;
	int price = 0;
	float vipPrice = 0;
	bool isVip = false;
	int noTicketPurchased = 0;
	int soldTicketsPerMonth[12];
	const int maxTickets = 0;

	Location loc;


public:

	int getMonthData(int monthIndex) {
		if (monthIndex > 11 || monthIndex < 0) {
			throw exception("Wrong month index.");
		}
		return this->soldTicketsPerMonth[monthIndex];
	}

	char* getTicketID() {
		return this->ticketID;
	};

	int getPrice() {
		return this->price;
	};

	float getVipPrice() {
		return this->vipPrice;
	};
	bool getIsVip() {
		return this->isVip;
	};


	void setPrice(int ticketPrice) {
		/*	if (ticketPrice <= 0 || ticketPrice <= this->vipPrice) {
				throw exception("Wrong price");
			}*/
		this->price = ticketPrice;
	};

	void setVipPrice(float vipPriceEvent) {
		/*	if (vipPriceEvent <= 0 || vipPriceEvent <= this->price) {
				throw exception("Wrong price");
			}*/
		this->vipPrice = vipPriceEvent;
	};

	void setIsVip(bool isVip) {
		this->isVip = isVip;
	};

	void setTicketId() {
		delete[] this->ticketID;
		this->ticketID = Util::copyString(Util::printstring(8).c_str());
	};


	Ticket() {
		this->setPrice(30);
		this->vipPricefifty();
		this->setIsVip(false);
		delete[] this->ticketID;
		this->ticketID = Util::copyString(Util::printstring(8).c_str());
		for (int i = 0; i < 12; i++) {
			this->soldTicketsPerMonth[i] = 0;
		}
		//this->bookTable(this->loc);
	};

	Ticket(bool isVip, int price, int vipPrice) {
		this->setVipPrice(vipPrice);
		this->setIsVip(isVip);
		this->setPrice(price);
		delete[] this->ticketID;
		this->ticketID = Util::copyString(Util::printstring(8).c_str());
		for (int i = 0; i < 12; i++) {
			this->soldTicketsPerMonth[i] = 0;
		}
		//this->bookTable(this->loc);

	};


	//postfix version
	Ticket operator++(int) {
		Ticket copy = *this;
		this->noTicketPurchased += 1;
		return copy;
	}

	//prefix version
	Ticket operator++() {
		this->noTicketPurchased += 1;
		return *this;
	}

	int& operator[](int index) {
		if (index < 0 || index > 11) {
			throw exception("Wrong month index");
		}
		return this->soldTicketsPerMonth[index];
	}

	bool operator==(Ticket t) {
		if (t.price == this->price) {
			return true;
		}
		else return false;
	}

	void bookTable(Location l) {
		l.ticketPurchased();

	}

	void vipPricefifty() {

		this->vipPrice = 50.0 / 100 * this->price + this->price;
	};



	//destructor
	~Ticket() {
		delete[] this->ticketID;
	}

	friend void operator<<(ostream& console, Ticket& tic);
	friend void operator>> (istream& is, Ticket& tic);

};
void operator>>(istream& is, Ticket& tic) {
	cout << endl << "Standard price: ";
	is >> tic.price;
	cout << endl << "VIP price: ";
	is >> tic.vipPrice;

}
void operator<<(ostream& console, Ticket& tic) {
	console << endl << "Standard price: " << tic.price;
	console << endl << "VIP price: " << tic.vipPrice;
}

class DiscountedTicket : public Ticket {

	int discount = 0;
public:
	DiscountedTicket() : Ticket(false, 30, 45) {
	};

	DiscountedTicket(float discount, float price, float vipPrice, bool isVip) : Ticket(isVip, price, vipPrice)
	{ }

	void setDiscount(int discount) {
		this->discount = discount;
	}

	float getDiscount() {
		float discprice = 0;
		discprice = this->getPrice() - ((this->discount * this->getPrice()) / 100.0);
		return discprice;
	}


};
