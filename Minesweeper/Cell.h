/*
 * ceil.h
 *
 *  Created on: 13 Kas 2017
 *      Author: sefa
 */

#ifndef CELL_H_
#define CELL_H_
#include <string>
class Cell
{
public:
	Cell();
	Cell(int row, int col, char value);
	Cell(int row, int col);
	Cell(int row, int col, char value, bool hide);
	virtual ~Cell();
	char getCellValue();
	void setCellValue(int v);
	char printCellValue(bool theEnd);
	bool isBomb();
	bool isSafe();
	bool isClose();
	bool isHidden();
	void setHide(bool h);

private:
	int row,col;
	char value;
	bool hide;


};

#endif /* CELL_H_ */
