#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
using namespace std;

int main()
{
    Ticket* t = new Ticket;
    Location* l = new Location;

    l->setAddress("?");
    cout << l->getAddress();
    cout << l;
}

