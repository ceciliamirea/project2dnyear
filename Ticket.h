#pragma once
#include <iostream>

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

class Ticket {
private:

	int ticketID=0;
	int price = 0;
	int vipPrice = 0;
	bool isVip = false;

public: 

	int getPrice() {
		return this->price;
	}

	int getVipPrice() {
		return this->vipPrice;
	}
	bool getIsVip() {
		return this->isVip;
	}

	void setPrice(int ticketPrice) {
		if (ticketPrice <= 0) {
			throw exception("wrong price")
		}
		this->price = ticketPrice;
	}

	void setVipPrice(int vipPriceEvent) {
		if (vipPriceEvent <= 0) {
			throw exception("wrong price")
		}
		this->vipPrice = vipPriceEvent;
	}

	void setIsVip(bool isVip) {
		this->isVip = isVip;
	}

	Ticket() {
		this->setPrice(30);
		this->setIsVip(false);
	}

	Ticket(bool isVip, int price, int vipPrice) {
		this->setVipPrice(vipPrice);
		this->setIsVip(isVip);
		this->setPrice(price);
	}

};
