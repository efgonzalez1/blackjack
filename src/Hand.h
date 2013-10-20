/*
 * Hand.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */

#ifndef HAND_H_
#include <vector>
using namespace std;
#define HAND_H_

class Hand {
public:
	Hand();
	virtual ~Hand();
	void addToHand(Card* card);
	void clear();
	int value() const;
	vector<Card*> cards;
};

Hand::Hand() {
}

Hand::~Hand() {
	clear();
}

void Hand::addToHand(Card* card) {
	cards.push_back(card);
}

void Hand::clear() {
	cards.clear();
}

int Hand::value() const {

	//Hide house's card value
	if (cards[0]->getValue() == 0) {
		return 0;
	}

	//Look for ace
	int value = 0;
	bool hasAce = false;
	vector<Card*>::const_iterator i;
	for (i = cards.begin(); i != cards.end(); i++) {
		if ((*i)->getValue() == Card::ACE) {
			hasAce = true;
		}
	}

	// Calculate value regularly if no Ace
	if (hasAce == false) {
		i = cards.begin();
		while (i != cards.end()) {
			value += (*i)->getValue();
			i++;
		}
	}

	// Calculate optimum value if Ace present
	else {
		// Use 11 for Ace when value is low enough
		if (value < 11) {
			i = cards.begin();
			while (i != cards.end()) {
				value += (*i)->getValue();
				i++;
			}
			value += 10;
		}
		// If value makes player bust, recalculate using 1 for Ace
		if (value >= 21) {
			value = 0;
			i = cards.begin();
			while (i != cards.end()) {
				value += (*i)->getValue();
				i++;
			}
		}
	}
	return value;
}

#endif /* HAND_H_ */
