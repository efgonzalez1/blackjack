/*
 * Player.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */


#ifndef PLAYER_H_
#include "Hand.h"
#include <string>
using namespace std;
#define PLAYER_H_

class Player: public Hand {

public:
	Player(string name = "");

	virtual bool keepHitting() const = 0;
	bool hasBusted();
	void announceBustMsg();
	string name;
};

Player::Player(string n) :
	name(n) {
}

bool Player::hasBusted() {
	if (value() > 21)
		return true;
	else
		return false;
}

void Player::announceBustMsg() {
	cout << name << " -- BUSTED" << endl;
}

#endif /* PLAYER_H_ */
