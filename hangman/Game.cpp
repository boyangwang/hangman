#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib> 
#include "Game.h"


Game::Game(string ans, int life_total) {
	_life_total = life_total; 
	_life_left = life_total;
	char _alphabet [] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	_ans = ans;
	_revealed = false;
	_correct = 0;
}

int Game::start() {
	string temp;
	do {
		cout << "\nLife_left: " << _life_left << '\n';
		// display word
		for (char& c : _ans) {
			if (find(_guessed.begin(), _guessed.end(), c) != _guessed.end()) {
				cout << c << ' ';
			}
			else {
				cout << "_ ";
			}
		}

		cout << "\n\nMake your guess: ";
		getline(cin, temp);
		char guess = tolower(temp[0]);
		
		if (guess > 122 || guess < 97) {
			cout << "\nInvalid!\n";
			continue;
		}
		else if (find(_guessed.begin(), _guessed.end(), guess) != _guessed.end()) {
			cout << "\nYou have guessed that letter before!\n";
			continue;
		}
		else {
			_guessed.push_back(guess);
			if (_ans.find(guess) != -1) {
				cout << "correct!\n";
				_correct++;
			}
			else {
				cout << "wrong!\n";
				_life_left--;
			}
			
			if (_correct == _life_total) {
				_revealed = true;
			}
		}
	} while (_life_left > 0 && !_revealed);

	if (!_revealed) {
		cout << "\nYou Lose! The answer is " << _ans << '\n';
		
	}
	else {
		cout << "\nYou Win! The answer is " << _ans << '\n';
		
	}
	char play_again = 'n';
	do {
		cout << "Do you want to play again? (y/n)\n";
		getline(cin, temp);
		play_again = tolower(temp[0]);
	} while (play_again != 'y' && play_again != 'n');

	if (play_again == 'y') {
		return 1;
	}
	else
		return -1;
}

Game::~Game()
{
}
