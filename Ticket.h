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
		for (int i = 0; i < 8; ++i)
		{
			id[i] += alphanum[rand() % stringLength];

		}
		return id;
	}
};

class Ticket {
private:

	char* ticketID;
	int price = 0;
	int vipPrice = 0;
	bool isVip = false;

public:


	char* getTicketID() {
		return this->ticketID;
	};

	int getPrice() {
		return this->price;
	};

	int getVipPrice() {
		return this->vipPrice;
	};
	bool getIsVip() {
		return this->isVip;
	};

	void setPrice(int ticketPrice) {
		if (ticketPrice <= 0 || ticketPrice >= this->vipPrice) {
			//throw exception("Wrong price");
		}
		this->price = ticketPrice;
	};

	void setVipPrice(int vipPriceEvent) {
		if (vipPriceEvent <= 0 || vipPriceEvent <= this->price) {
			//throw exception("Wrong price");
		}
		this->vipPrice = vipPriceEvent;
	};

	void setIsVip(bool isVip) {
		this->isVip = isVip;
	};

	void setTicketId() {
		this->ticketID = Util::genRandom();
		//this->ticketID = Util::copyString(genRandom());
	};


	Ticket() {
		this->setPrice(30);
		this->setIsVip(false);
		this->setTicketId();
	};

	Ticket(bool isVip, int price, int vipPrice) {
		this->setVipPrice(vipPrice);
		this->setIsVip(isVip);
		this->setPrice(price);
		this->setTicketId();
	};

	void vipPricefifty() {

		this->vipPrice = 50 / 100 * this->price + this->price;
	};





};
