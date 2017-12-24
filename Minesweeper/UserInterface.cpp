/*
 * UserInterface.cpp
 *
 *  Created on: 25 Kas 2017
 *      Author: sefa
 */

#include "UserInterface.h"
#include <iostream>
#include "Board.h"
#include "Cell.h"
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

UserInterface::UserInterface() {
	// TODO Auto-generated constructor stub

}

UserInterface::~UserInterface() {
	// TODO Auto-generated destructor stub
}

void UserInterface::displayMenu() {
	string input;
	bool control = false;

	cout << "\t █████╗ ███╗   ███╗ █████╗ ███████╗██╗███╗   ██╗ ██████╗      \n"
			"\t██╔══██╗████╗ ████║██╔══██╗╚══███╔╝██║████╗  ██║██╔════╝      \n"
			"\t███████║██╔████╔██║███████║  ███╔╝ ██║██╔██╗ ██║██║  ███╗     \n"
			"\t██╔══██║██║╚██╔╝██║██╔══██║ ███╔╝  ██║██║╚██╗██║██║   ██║     \n"
			"\t██║  ██║██║ ╚═╝ ██║██║  ██║███████╗██║██║ ╚████║╚██████╔╝     \n"
			"\t╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═══╝ ╚═════╝      \n";

	cout << "\t_  _ _ _  _ ____ ____ _ _ _ ____ ____ ___  ____ ____   \n"
			"\t|\\/| | |\\ | |___ [__  | | | |___ |___ |__] |___ |__/   \n"
			"\t|  | | | \\| |___ ___] |_|_| |___ |___ |    |___ |  \\ \n" << endl;

	cout << "Please Enter your name: ";
	getline(cin, userName);

	do {
		cout << "1. Play Game \n";
		cout << "2. How to Play \n";
		cout << "3. Show Last Achievement \n";
		cout << "4. Exit \n>> ";
		getline(cin, input);

		// input should be from 1 to 4 and in ASCII table shows that 49=1, 50=2, 51=3, 52=4
		// and also input should 1 character so that length = 1.
		if (((input[0] > 48 && input[0] < 53) && input.length() == 1)) {
			input[0] = input[0] - 48;
		} else
			cout << ">> Not a valid choose! \n" << endl;

		switch (input[0]) {
		case 1:
			clearConsole();
			playGame();
			break;
		case 2:
			clearConsole();
			howToPlay();
			break;
		case 3:
			clearConsole();
			loadAchievement();
			break;
		case 4:
			exit(0);
			break;
		default:
			control = true;

		}
	} while (control);

}
void UserInterface::playGame() {
	string rStr, cStr;
	string inputRowStr, inputColStr;
	int r, c;
	int inputRow, inputCol;

	cout<< "You can define your own board, please enter a row and column number to size of board" << endl;
	cout << "Note: The numbers should be greater than 2 !! \n" << endl;
	cout << "Please enter size of row: ";
	cin >> inputRowStr;
	cout << "Please enter size of column: ";
	cin >> inputColStr;

	if (checkInput(inputRowStr, inputColStr)) {
		stringstream rInt(inputRowStr);
		stringstream cInt(inputColStr);
		rInt >> inputRow;
		cInt >> inputCol;
	} else {
		playGame();
	}

	if (inputRow < 3 || inputCol < 3) {
		clearConsole();
		cout << "Note: The numbers should be greater than 2 !! \n" << endl;
		playGame();

	}

	clearConsole();

	this->board = new Board(inputRow, inputCol);
	this->board->initBoard();
	this->board->printBoard(false);
	bool endGame = false;

	do {
		cout << "Please enter a number of row: ";
		cin >> rStr;
		cout << "Please enter a number of col: ";
		cin >> cStr;

		if (checkInput(rStr, cStr)) {
			stringstream rInt(rStr);
			stringstream cInt(cStr);
			rInt >> r;
			cInt >> c;

			clearConsole();
			endGame = this->board->endOfGame(r, c);
		}
		this->board->printBoard(endGame);

	} while (!endGame);

	cout << endl;
	checkAfterGame();
}
bool UserInterface::checkInput(string rStr, string cStr) {
	for (int i = 0; i < rStr.length(); i++) {
		if (!isdigit(rStr[i]) || !isdigit(cStr[i])) {
			clearConsole();
			cout << "Invalid input!!  Please try again carefully! \n" << endl;
			return false;
		}
	}
	return true;
}

void UserInterface::howToPlay() {
	string information;
	cout << "--------Minesweeper Game--------- \n\n";

	// write how to play
	cout << "--> Minesweeper game is a board game which plays just one player.\n";
	cout << "--> Before the starting game, player should enter the number of board size (row and column size). \n";
	cout << "--> Do not forget! when board size is increase, the number of mines will rise automatically so that higher of board size will be more difficult. \n";
	cout << "--> After choosing board size, the game will start and player should enter row and column number for opening the cell. \n\n";
	cout << "--> After opening the cell; \n-->1.Option: The number will appear. This number will be clue that player can understand around the cell, there are how many mine. \n";
	cout << "--> 2.Option: if the cell which is opened by player contains a mine, the game will finish and player will be lost. \n";
	cout << "--> 3.Option: However, if player opens all mine-free cells, player will be won the game. \n\n";
	cout << "--> After the every game, some information about the last game will save in a text file and player can check the board size and start the new game with different board sizes. \n";
	cout << "--> Players can increase the size of the board starting from the smallest board and force their limits!! \n\n";
	cout << "--------Have a good game!--------- \n" << endl;

	bool howToinformation = false;
	do {
		cout << "1. To Start the Game \n>>";
		cin >> information;

		if (information == "1") {
			playGame();
		} else {
			cout << "Not valid input!! \n" << endl;
		}
	} while (!howToinformation);
}

//When the game finish the options of play again and exit..
void UserInterface::checkAfterGame() {
	string press;
	bool afterGame = false;
	saveAchievement();

	do {
		cout << "Press 1 to show this game information and play again.. \n";
		cout << "Press 2 to To Exit \n>> ";
		cin >> press;
		clearConsole();
		if (press == "1") {
			loadAchievement();
		} else if (press == "2") {
			exit(0);
		} else
			cout << "Not valid input!! \n" << endl;
	} while (!afterGame);
}

void UserInterface::lastAchievement() {
	string inputAch;
	bool control1 = false;

	do {
		cout << endl;
		cout << "1. To Start New Game \n";
		cout << "2. To exit \n>>";
		cin >> inputAch;
		if (inputAch == "1") {
			playGame();
		} else if (inputAch == "2") {
			exit(0);
		} else {
			cout << "Invalid input !! \n" << endl;
		}
	} while (!control1);

}

void UserInterface::loadAchievement() {
	ifstream iFile;
	iFile.open("SavedAchievement.txt", ifstream::in);

	if (iFile.fail()) {
		cerr << "There is error when opening file!!" << endl;
	}

	cout << "Last Game informations >> \n" << endl;
	while (iFile.good()) {
		cout << (char) iFile.get();
	}
	cout << endl;
	//iFile.close(); --> Sagmantation fault!!
	lastAchievement();
}

void UserInterface::saveAchievement() {
	string s = "Username:" + this->userName + "\n";
	s += "Chosen the number of row:" + to_string(board->getRow()) + "\n";
	s += "Chosen the number of column:" + to_string(board->getCol()) + "\n";
	s += "The number of cell of hide has left:" + to_string(board->countHides)	+ "\n";
	s += "The number of bomb:" + to_string(board->countMines) + "\n\n";

	if (board->countHides == board->countMines) {
		s += "Last Game Status: You won last game!! \n";
	} else {
		s += "Last Game Status: You lost last game!!";
	}

	ofstream outFile("SavedAchievement.txt");
	outFile << s;
	outFile.close();
}

void UserInterface::clearConsole() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	cout << "\x1B[2J\x1B[H";
}

