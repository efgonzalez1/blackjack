/*
 * Game.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */

#ifndef GAME_H_
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
using namespace std;
#define GAME_H_

class Game {
public:
	Game(const vector<string>& names);
	void play();
	string displayCard(Card&);
	string buildDisplayItem(Player&);
private:
	Deck d;
	House h;
	vector<Human> players;
};

Game::Game(const vector<string>& names) {
	// Start game after users enter their names
	vector<string>::const_iterator n;
	for (n = names.begin(); n != names.end(); n++) {
		players.push_back(Human(*n));
	}

	//Seed the random number generator
	srand(static_cast<unsigned int> (time(0)));
	d.createDeck();
	d.shuffle();
}

void Game::play() {
	//Deal first 2 cards
	vector<Human>::iterator p;
	for (int i = 0; i < 2; ++i) {
		for (p = players.begin(); p != players.end(); p++) {
			d.deal(*p);
		}
		d.deal(h);
	}

	//Hide 1 house card
	h.flipFirstCard();

	// Prevents unsigned int warning
	signed int size = players.size();

	//Display hands
	for (int i = 0; i < size; i++) {
		cout << buildDisplayItem(players.at(i)) << ":\t" << endl;
	}
	cout << buildDisplayItem(h) << endl;

	//Deal cards when players hit
	for (p = players.begin(); p != players.end(); p++) {
		d.dealHit(*p);
	}

	//Show the other house card
	h.flipFirstCard();
	cout << endl << buildDisplayItem(h);

	// Deal to the house
	d.dealHit(h);

	if (h.hasBusted()) {
		//Everyone wins when the house busts
		for (p = players.begin(); p != players.end(); p++) {
			if (!(p->hasBusted())) {
				p->win();
			}
		}
	} else {
		// Evaluate winner
		for (p = players.begin(); p != players.end(); p++) {
			if (!(p->hasBusted())) {
				if (p->value() > h.value()) {
					p->win();
				} else if (p->value() < h.value()) {
					p->lose();
				} else {
					p->push();
				}
			}
		}

	}

	//Remove cards for new game
	for (p = players.begin(); p != players.end(); p++) {
		p->clear();
	}
	h.clear();
}

string Game::displayCard(Card& card) {
	stringstream ss;
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "J", "Q", "K" };
	const string SUITS[] = { "-D", "-S", "-H", "-C" };
	if (card.isFaceUp) {
		ss << RANKS[card.cardRank];
		ss << SUITS[card.cardSuit];
	} else {
		ss << "---";
	}
	return ss.str();
}

string Game::buildDisplayItem(Player& player) {
	stringstream ss;
	ss << player.name << ":\t";

	signed int size = player.cards.size();
	vector<Card*>::const_iterator pCard;
	if (!player.cards.empty()) {
		for (int i = 0; i < size; i++) {
			ss << displayCard(*(player.cards.at(i)));
			ss << "\t";
		}
	}
	if (player.value() != 0) {
		ss << "(" << player.value() << ")";
	}
	return ss.str();
}

#endif /* GAME_H_ */
