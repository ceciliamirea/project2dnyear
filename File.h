#pragma once
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Location.h"
#include "Event.h"
#include <fstream>
using namespace std;


class File {

public:
    ifstream inputFile;

    File(const string& Text) {
        inputFile.open(Text);
    }
    File() {}

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

    void BinaryFile(string dataf, string fileName) {
        ofstream inputFile;
        string s = "/";
        for (int i = 0; i < fileName.size(); i++)
            if (s.find(fileName[i]) != -1) {
                fileName.erase(fileName.begin() + i), i--;
                fileName.insert(fileName.begin() + i + 1, '_'), i++;
            }
        ofstream bf(fileName, ios::binary);
        if (!bf) {
            cout << "Unable to open file for writing!" << endl;
            return;
        }
        string data = dataf;
        bf.write((char*)&data, sizeof(data));
        bf.close();


    }
};