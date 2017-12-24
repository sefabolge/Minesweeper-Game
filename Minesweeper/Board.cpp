/*
 * Board.cpp
 *
 *  Created on: 13 Kas 2017
 *      Author: sefa
 */

#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Cell.h"
#include "UserInterface.h"


#include <sstream>

using namespace std;

Board::Board() {
	// TODO Auto-generated constructor stub
}
Board::Board(int row, int col) {

	this->row = row;
	this->col = col;
	// dynamic memory allacation
	this->array.reserve(row);
	for (int i = 0; i < row; i++) {
		array[i].reserve(col);
	}

	this->countHides = row*col;
	int pow = (row * col);
	this->countMines = (pow - (pow % 6)) / 6;

}

Board::~Board() {

}

void Board::initBoard() {
	for (int r = 0; r < this->row; r++) {
		for (int c = 0; c < this->col; c++) {
			array[r][c] = new Cell(r, c);
		}
	}
	placeMines(); 
	setCloseFields();
}

void Board::printBoard(bool theEnd) {
	cout <<"-------------------------------------------" << endl;
	cout << "Count of Cells ["<<countHides<<"] \t";
	cout <<"Total of mines ["<<countMines<<"] \n";
	cout <<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;


	for (int r = 0; r < this->row; r++) {
		for (int c = 0; c < this->col; c++) {
			cout << " " << array[r][c]->printCellValue(theEnd); 
		}

		cout << endl;
	}
}

bool Board::endOfGame(int r, int c) {

	if (checkChoise(r,c)){
		if (array[r][c]->isSafe()) {
			showCell(array[r][c]);
			checkNeighbor(r, c);
		} else if (array[r][c]->isClose()) {
			showCell(array[r][c]);
		}
		if (array[r][c]->isBomb()){
			cout << "Oh shit, Bomb found!!  GAME OVER! \n" << endl;
			return true;
		}
		if(countHides == countMines){
			cout << "Congratulations!!  YOU WON!\n" << endl;
			return true;
		}
			return false;
		}
	return false;
}

void Board::checkNeighbor(int r, int c) {

	if (this->col > (c + 1) && 0 <= (c + 1) ) {
		if(array[r][c + 1]->isHidden()){
			if (array[r][c + 1]->isSafe()) {
				showCell(array[r][c + 1]);
				checkNeighbor(r, c + 1);
			}
		}
	}
	if (this->row > (r + 1) && 0 <= (r + 1)) {
		if(array[r+1][c]->isHidden()){
		if (array[r + 1][c]->isSafe()) {
			showCell(array[r + 1][c]);
			checkNeighbor(r + 1, c);
		}}

	}
	if (0 <= (c - 1)) {
		if(array[r][c - 1]->isHidden()){
		if (array[r][c - 1]->isSafe()) {
			showCell(array[r][c - 1]);
			checkNeighbor(r, c - 1);
		}
		}
	}
	if (0 <= (r - 1) && this->row > (r - 1)) {
		if(array[r-1][c]->isHidden()){
		if (array[r - 1][c]->isSafe()) {
			showCell(array[r - 1][c]);
			checkNeighbor(r - 1, c);
		}
		}
	}

	if (0 <= (r - 1) && 0 <= (c- 1) && this->row > (r - 1) && this->col > (c-1)) {
		if(array[r-1][c-1]->isHidden()){
			if (array[r - 1][c - 1]->isSafe()) {
				showCell(array[r - 1][c - 1]);
				checkNeighbor(r - 1, c - 1);
			}
		}
	}
	if (0 <= (r - 1) && 0 <= (c + 1) && this->row > (r - 1) && this->col > (c + 1)) {
		if(array[r-1][c+1]->isHidden()){
			if (array[r - 1][c + 1]->isSafe()) {
				showCell(array[r - 1][c + 1]);
				checkNeighbor(r - 1, c + 1);
			}
		}
	}
	if (0 <= (r + 1) && 0 <= (c - 1) && this->row > (r + 1) && this->col > (c - 1)) {
		if(array[r+1][c-1]->isHidden()){
			if (array[r + 1][c - 1]->isSafe()) {
				showCell(array[r + 1][c - 1]);
				checkNeighbor(r + 1, c - 1);
			}
	}
	}
	if (0 <= (r + 1) && 0 <= (c + 1) && this->row > (r + 1) && this->col > (c + 1)) {
		if(array[r+1][c+1]->isHidden()){
			if (array[r + 1][c + 1]->isSafe()) {
				showCell(array[r + 1][c + 1]);
				checkNeighbor(r + 1, c + 1);
			}
		}
	}


	if (this->col > (c + 1) && 0 <= (c + 1)) {
			if (array[r][c + 1]->isClose()){
				showCell(array[r][c + 1]);
			}
	}
	if (this->row > (r + 1) && 0 <= (r + 1)) {
			if (array[r + 1][c]->isClose()){
				showCell(array[r + 1][c]);
			}
		}
	if (0 <= (c - 1) && this->col > (c - 1)) {
			if (array[r][c - 1]->isClose()) {
				showCell(array[r][c - 1]);

			}
		}
	if (0 <= (r - 1) && this->row > (r - 1)) {
			if (array[r - 1][c]->isClose()) {
				showCell(array[r - 1][c]);
			}
		}

	if (0 <= (r - 1) && 0 <= (c - 1) && this->row > (r - 1) && this->col > (c - 1)) {

			if (array[r - 1][c - 1]->isClose()) {
				showCell(array[r - 1][c - 1]);
			}
		}
	if (0 <= (r - 1) && 0 <= (c + 1) && this->row > (r - 1) && this->col > (c + 1)) {

			if (array[r - 1][c + 1]->isClose()) {
				showCell(array[r - 1][c + 1]);
			}
		}
	if (0 <= (r + 1) && 0 <= (c - 1) && this->row > (r + 1) && this->col > (c - 1)) {

			if (array[r + 1][c - 1]->isClose()) {
				showCell(array[r + 1][c - 1]);
			}
		}
	if (0 <= (r + 1) && 0 <= (c + 1) && this->row > (r + 1) && this->col > (c + 1)) {

			if (array[r + 1][c + 1]->isClose()) {
				showCell(array[r + 1][c + 1]);
			}
		}
}

bool Board::checkChoise(int r, int c) {
	if (r < this->row && c < this->col) {
		return true;
	}else {
		return false;
	}
}

//Set random bomb on the board
void Board::placeMines() {
	int numofMines = 0;
	int a, b;
	srand(time(0)); 

	do {
		do {
			a = rand() % this->row;
			b = rand() % this->col;
		} while (array[a][b]->getCellValue() != '0');
		array[a][b] = new Cell(a, b, '*');
		numofMines++;
	} while (numofMines < this->countMines);
}

void Board::showCell(Cell* c){
	if(c->isHidden()){
		this->countHides--;
		c->setHide(false);
	}
}

// Count a number which is around the bomb..
void Board::setCloseFields() {

	for (int r = 0; r < this->row; r++) {
		for (int c = 0; c < this->col; c++) {
			int findBomb = 0;
			if (r > 0 && c > 0 && r < row - 1 && c < col - 1) {
				if (array[r - 1][c - 1]->isBomb())
					findBomb++;
				if (array[r][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c - 1]->isBomb())
					findBomb++;
				if (array[r - 1][c]->isBomb())
					findBomb++;
				if (array[r + 1][c]->isBomb())
					findBomb++;
				if (array[r - 1][c + 1]->isBomb())
					findBomb++;
				if (array[r][c + 1]->isBomb())
					findBomb++;
				if (array[r + 1][c + 1]->isBomb())
					findBomb++;
			} else if (r == 0 && c == 0) {
				if (array[r][c + 1]->isBomb())
					findBomb++;
				if (array[r + 1][c + 1]->isBomb())
					findBomb++;
				if (array[r + 1][c]->isBomb())
					findBomb++;
			} else if (r == 0 && c == col - 1) {
				if (array[r][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c]->isBomb())
					findBomb++;
			} else if (r == row - 1 && c == 0) {
				if (array[r - 1][c]->isBomb())
					findBomb++;
				if (array[r - 1][c + 1]->isBomb())
					findBomb++;
				if (array[r][c + 1]->isBomb())
					findBomb++;
			} else if (r == row - 1 && c == col - 1) {
				if (array[r - 1][c - 1]->isBomb())
					findBomb++;
				if (array[r][c - 1]->isBomb())
					findBomb++;
				if (array[r - 1][c]->isBomb())
					findBomb++;
			} else if (r == 0 && c > 0) {
				if (array[r][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c]->isBomb())
					findBomb++;
				if (array[r + 1][c + 1]->isBomb())
					findBomb++;
				if (array[r][c + 1]->isBomb())
					findBomb++;
			} else if (r > 0 && c == 0) {
				if (array[r - 1][c]->isBomb())
					findBomb++;
				if (array[r - 1][c + 1]->isBomb())
					findBomb++;
				if (array[r][c + 1]->isBomb())
					findBomb++;
				if (array[r + 1][c + 1]->isBomb())
					findBomb++;
				if (array[r + 1][c]->isBomb())
					findBomb++;
			} else if (r == row - 1 && c > 0) {
				if (array[r][c - 1]->isBomb())
					findBomb++;
				if (array[r - 1][c - 1]->isBomb())
					findBomb++;
				if (array[r - 1][c]->isBomb())
					findBomb++;
				if (array[r - 1][c + 1]->isBomb())
					findBomb++;
				if (array[r][c + 1]->isBomb())
					findBomb++;
			} else if (r > 0 && c == col - 1) {
				if (array[r - 1][c]->isBomb())
					findBomb++;
				if (array[r - 1][c - 1]->isBomb())
					findBomb++;
				if (array[r][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c - 1]->isBomb())
					findBomb++;
				if (array[r + 1][c]->isBomb())
					findBomb++;
			}

			if (!array[r][c]->isBomb()) {

				array[r][c]->setCellValue(findBomb);
			}
		}
	}
}

int Board::getRow(){
	return this->row;
}
int Board::getCol(){
	return this->col;
}