/*
 * UserInterface.h
 *
 *  Created on: 25 Kas 2017
 *      Author: sefa
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include <string>
#include "Board.h"

using namespace std;

class UserInterface {
public:
	UserInterface();
	virtual ~UserInterface();
	void clearConsole();
	void displayMenu();
	void playGame();
	void howToPlay();
	void lastAchievement();
	void checkAfterGame();
	void enterName();
	void saveAchievement();
	bool checkInput(string rStr, string cStr);
	void loadAchievement();
private:
	string userName;
	Board *board;

};

#endif /* USERINTERFACE_H_ */
