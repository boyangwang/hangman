#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib> 
#pragma once
using namespace std;

class Game
{
	bool _revealed;
	int _correct;
	string _ans;
	char _alphabet[26];
	vector<char> _guessed;
	int _life_left;
	int _life_total;
public:
	Game(string ans, int life_total);
	~Game();
	int start();
};

