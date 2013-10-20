/*
 * Human.h
 *
 *  Created on: May 4, 2011
 *      Author: Fernando
 */



#ifndef HUMAN_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#define HUMAN_H_

class Human: public Player {
public:
	virtual ~Human();
	Human(const string& name = "");
	virtual bool keepHitting() const;
	void win() const;
	void lose() const;
	void push() const;
};


Human::Human(const string& name) :
	Player(name) {
}

Human::~Human() {
}
bool Human::keepHitting() const {
	char response;
	cout << "Hit again, " << name << "? (Y/N): ";
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Human::win() const {
	cout << name << " -- WINNER\n";
}

void Human::lose() const {
	cout << name << " -- LOSES\n";
}

void Human::push() const {
	cout << name << " -- PUSHES\n";
}


#endif /* HUMAN_H_ */
