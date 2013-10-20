/*
 * House.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */



#ifndef HOUSE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#define HOUSE_H_

class House: public Player {
public:
	virtual ~House();
	House(const string& name = "House");
	virtual bool keepHitting() const;
	void flipFirstCard();
};

House::~House() {
}

House::House(const string& name) :
	Player(name) {
}

bool House::keepHitting() const {
	// House hits when its card value <= 16
	return (value() <= 16);
}

void House::flipFirstCard() {
	if (!(cards.empty())) {
		cards[0]->flip();
	}
}

#endif /* HOUSE_H_ */
