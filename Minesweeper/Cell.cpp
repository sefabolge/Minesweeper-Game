/*
 * cell.cpp
 *
 *  Created on: 13 Kas 2017
 *      Author: sefa
 */
#include <iostream>
#include "Cell.h"
#include <stdlib.h>
#include <ctype.h>
#include <string>

using namespace std;

Cell :: Cell (){
}

Cell::Cell(int row, int col, char value, bool hide) {
	this->row = row;
	this->col = col;
	this->value = value;
	this->hide = hide;

}

Cell::Cell(int row, int col, char value) {
	this->row = row;
	this->col = col;
	this->value = value;
	this->hide = true;

}

Cell::Cell(int row, int col) {
	this->row = row;
	this->col = col;
	this->value = '0';
	this->hide = true;

}

Cell::~Cell() {

	//delete[] value;
}
void Cell :: setCellValue(int v){
	v = v+48; // ASCI TABLE 
	char c = v;
	this->value = c;
}

char Cell :: getCellValue(){
	return this->value;
}

char Cell :: printCellValue(bool theEnd){

	char ret;
	if(hide && !theEnd){

		cout << "\u25CC";
	}else {
		ret = this->value;
	}

	return ret;

}

bool Cell :: isBomb(){
	if(this->value == '*')
		return true;
	else
		return false;
	}

bool Cell :: isSafe(){
	return (value == '0');
}

bool Cell :: isClose(){
	return isdigit(value);
}
bool Cell :: isHidden(){
	return this->hide;
}
void Cell :: setHide(bool h){
	this->hide = h;
}
