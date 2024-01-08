#pragma once
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
#include <fstream>
using namespace std;

class UtilF {
public:

    static void readString(ifstream& file, string& value) {
        int d;
        file.read((char*)&d, sizeof(int));
        char buffer[1000];
        file.read(buffer, d * sizeof(char));
        value = string(buffer);
    }
};

class File {
private:
    ifstream inputFile;

public:
    File(const string& Text) {
        inputFile.open(Text);
    }

    void displayContents() {
        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                cout << line << endl;
            }
            inputFile.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
};