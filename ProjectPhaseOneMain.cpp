#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
using namespace std;

int main()
{
	Location location;
	cout << location;
	cout << endl;
	cout << location.getAddress() << endl;
	cout << location.getName() << endl;
	cout << location.getNoTables();
	cout << endl;

	location.setName("Bucuresti");
	cout << location;

	Location loc("Ct", "Adr", 15, 4);
	cout << loc;

	Location ceva = ++loc;
	cout << ceva;

	Ticket ticket;
	cout << ticket;
	cout << endl;
	cout << ticket.getPrice() << endl;
	cout << ticket.getTicketID() << endl;

	Event event;
	cout << event;
	cout << endl;
	cout << event.getName() << endl;
	cout << event.getSpecificBand(1) << endl;
	event.setDate("27/08/2024");
	cout << event;

}

