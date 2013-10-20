//============================================================================
// Name        : Blackjack.cpp
// Author      : E. Fernando Gonzalez
// Version     : v1.0
// Copyright   : 2011
// Description : Simple blackjack game using polymorphism and inheritance. Players
// can hit or stay. No betting implemented.
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "House.h"
#include "Human.h"
#include "Player.h"
#include "Game.h"

using namespace std;

int main() {
	int numPlayers = 0;
	vector<string> names;
	string name;

	cout << "Blackjack!" << endl;
	cout << "----------" << endl;

	while (numPlayers < 1 || numPlayers > 7) {
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}

	for (int i = 0; i < numPlayers; ++i) {
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	//Loop until user quits
	Game g(names);
	char answer = 'y';
	while (answer != 'n' && answer != 'N') {
		g.play();
		cout << "\nPlay again? (Y/N): ";
		cin >> answer;
	}
	return 0;
}
