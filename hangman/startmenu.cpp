#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "startmenu.h"

using namespace std;

startmenu::startmenu(vector<string> dict) {
	_dict = dict;
	system("CLS");

}

int startmenu::display() {
	cout << "Welcome to the Hangman Game!\n";
	while (true) {
		cout << "\n\t1. Start a New Game\n";
		cout << "\t2. Exit\n";
		cout << "\nPlease Select: ";
		string select_str;
		int select;
		getline(cin, select_str);
		stringstream(select_str) >> select;
		if (select == 2) {
			return 0;
		}
		else if (select == 1){
			cout << "\nGame Commencing...\n\n";
			return 1;
		}
		else {
			cout << "\nInvalid. Input again.\n\n";
		}
	}
}

startmenu::~startmenu()
{
}
