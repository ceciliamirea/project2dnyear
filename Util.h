#pragma once
#include <iostream>
#include <string>
using namespace std;

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
		for (unsigned int i = 0; i < 8; ++i)
		{
			id[i] += alphanum[rand() % stringLength];

		}
		return id;

	}

	static string printstring(int n)
	{
		char letters[36] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
		'r','s','t','u','v','w','x',
		'y','z','1','2','3','4','5','6','7','8','9','0' };
		string ran = "";
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			ran = ran + letters[rand() % 36];
		return ran;
	}
};
