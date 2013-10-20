/*
 * Deck.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */

#ifndef DECK_H_
#include "Player.h"
#include "Hand.h"
#include <iostream>
using namespace std;
#define DECK_H_

class Deck: public Hand {
public:
	Deck();
	void createDeck();
	void shuffle();
	void deal(Hand& hand);
	void dealHit(Player& player);
	string displayCard(Card&);
	string buildDisplayItem(Player&);
};

Deck::Deck() {
	cards.reserve(52);
	createDeck();
}

void Deck::createDeck() {
	clear();
	//Populate deck
	for (int s = Card::DIAMONDS; s <= Card::CLUBS; ++s) {
		for (int r = Card::ACE; r <= Card::KING; ++r) {
			addToHand(
					new Card(static_cast<Card::rank> (r),
							static_cast<Card::suit> (s)));
		}
	}
}

void Deck::shuffle() {
	random_shuffle(cards.begin(), cards.end());
}

void Deck::deal(Hand& hand) {
	if (!cards.empty()) {
		hand.addToHand(cards.back());
		cards.pop_back();
	} else {
		createDeck();
		deal(hand);
	}
}

void Deck::dealHit(Player& player) {
	cout << endl;
	// Keep dealing until player busts
	while (!(player.hasBusted()) && player.keepHitting()) {
		deal(player);
		cout << buildDisplayItem(player) << endl;
		if (player.hasBusted()) {
			player.announceBustMsg();
		}
	}
}

string Deck::displayCard(Card& card) {
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

string Deck::buildDisplayItem(Player& player) {
	stringstream ss;
	ss << player.name << ":\t";

	signed int size = player.cards.size();
	vector<Card*>::iterator c;
	if (!player.cards.empty()) {
		for (int i = 0; i < size; i++) {
			ss << displayCard(*(player.cards.at(i)));
			ss << "\t";
		}
	}

	if (player.value() != 0) {
		ss << "(" << player.value() << ")";
	} else {
		ss << "<empty>";
	}
	return ss.str();
}

#endif /* DECK_H_ */
