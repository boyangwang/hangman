#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "startmenu.h"
#include "Game.h"

using namespace std;

int main() {
	srand((unsigned int)time(0));
	cout << "Welcome to Hangman!\n";
	cout << "Initializing...\n";

	// Reading wordlist
	fstream myfile;
	vector<string> dic;
	myfile.open("wordlist.txt");

	while (!myfile.eof()) {
		string bf;
		getline(myfile, bf);
		dic.push_back(bf);
	}

	myfile.close();
	cout << "Number of words in dictionary: " << dic.size() << '\n';

	// Pass control to start menu
	startmenu sm = startmenu(dic);

	int menu_status = 2;
	int status = -1;
	do {
		menu_status = sm.display();
		if (menu_status == 1) {
			string ans = dic[rand() % dic.size()];
			
			Game cur_game = Game(ans, ans.size());
			status = cur_game.start();
		}
	} while (status == 1);

	return 0;
}