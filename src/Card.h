/*
 * Card.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */

#ifndef CARD_H_
#define CARD_H_

class Card {
	// This class defines generic properties of a card
public:
	enum rank {
		ACE = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 10,
		QUEEN = 10,
		KING = 10
	};
	enum suit {
		DIAMONDS, SPADES, HEARTS, CLUBS
	};
	Card(rank, suit, bool fu = true);
	int getValue();
	void flip();
	rank cardRank;
	suit cardSuit;
	bool isFaceUp;
};

Card::Card(rank r, suit s, bool fu) :
	cardRank(r), cardSuit(s), isFaceUp(fu) {
}

int Card::getValue() {
	//Return values of faceup cards only
	int value = 0;
	if (isFaceUp) {
		value = cardRank;
	}
	return value;
}

void Card::flip() {
	//Card becomes opposite of current state
	isFaceUp = !(isFaceUp);
}

#endif /* CARD_H_ */
