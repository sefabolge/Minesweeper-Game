/*
 * Board.h
 *
 *  Created on: 13 Kas 2017
 *      Author: sefa
 */
#include <vector>
#include "Cell.h"
#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

class Board {
public:
	Board();
	Board(int row, int col);
	virtual ~Board();
	void initBoard();
	void printBoard(bool theEnd);
	void setCloseFields();
	bool checkChoise(int r, int c);
	bool choise(int r, int c);
	bool endOfGame(int r, int c);
	void checkNeighbor(int r, int c);
	void showCell(Cell* c);
	int getRow();
	int getCol();
	string getArrayStr();
	void loadBoard(int row, int col, string arr);
	int countHides;
	int countMines;

private:
	int col,row;
	vector<vector<Cell*> > array;
	void placeMines();


};

#endif /* BOARD_H_ */
