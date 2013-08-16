#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib> 
#pragma once

using namespace std;

class startmenu {
	vector<string> _dict;
public:
	startmenu(vector<string> dict);
	~startmenu();
	int display();
};
