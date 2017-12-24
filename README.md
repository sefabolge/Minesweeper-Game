INTRODUCTİON

Minesweeper game is a board game which plays just one player. In this game, player can choose own board size and mines will defined according to the size of the board. When board size is increase, the number of mines will rise automatically so that higher of boardsize will be have more difficult game. After choosing the bord size, the game will star and all the board cell will be closed. The main logic of the game, player will open(input row and column) a cell and then a number will appear. This number will be clue that player can understand around the cell, there are how many mine. For instance, the number 2 on the opened cell means that there are 2 mines around the cell and also if the number is 0, the cells will open until the cells containing the mine. Player will continue open the cells but if the cell which is opened by player, contain a mine the game will finish and player will  be lost. However, if player opens all mine-free cells, player will be won the game. After the every game, some information about the last game will save in a text file such as player name, row, col the number hides and mines and also result the game. Thus, player can load this information and see last game achievement. Players can continue the game with a new difficult board size by seeing the information of the previous game and changing the board size accordingly. Moreover, the players can see where they have won and lost the last game and increase the size of the board over time and improve themselves. Forthermore, before playing game, player can read how to play game in the menu and has a idea about game.

THE PROGRAM ISSUES

There was several issue and some of it was not find out easily a few examples; “ Segmentation fault fault: Core dumped”, “floating point exception (core dumped)” and “Aborted (core dumped)”. When the research the internet what the means segmantation fault, “Segmentation means that means that you  tried to access memory that you do not have access to”. Subsequently, I found the problem and solve that was value of “array.reserve” and I believe that this kind of problem because of memory allocations (arrays define as ready in standart minesweeper game but in my project, array will define by player, and this created some memory issue). On the other hand, data type issues created some problem like converting data type  particularly char to int. 

FUNCTION/CLASS EXPLANATION

This game is a board game and I thought that firstly I need create board and then fill the inside of the board because I have to think every cell behaviour. There are two fundamental class, Cell class is defined for every cell behaviour for example what does the cell contain, it is mine(isBomb()), ‘0 (isSafe())’ or any value (isClose()). Moreover, I thought that board should include open and close style and I hide the number instead of creating two board (open board, close board). On the other hand, initialisation and printing board defined in Board class which is used cell class.

Board class:
placeMines(): board should contain mines and also this mines should be randomly in this function create mines in the board and also there is some calculation about how many mines in the board and countMines determined the number of mines.  
setCloseFields(): the player must have a clue because when player open a cell, is there any mines around the cell. This medhod will show a number that means how many bomb around the cell.
checkNeighbor(): in this case, player can see ‘0’ this means that cell is safe and  around the cell there is no mines so that cells will open until cells which is include mines.
endOfGame(): firsty, this method will check for every cell. For instance, player open the any cell and it contains ‘0’(isSafe) program will go to checkNeighbor() method or cell cantains any number (isClose) that player should understand around the cell  there is how many mine. Lastly, this method will check that player won or lost.

Furthermore, UserInterface() class include interface code (main menu) and also save and load file (last achivement) defined in this class.


APPROACH

After choosing this game for writing, firstly, I thougt, do I need two board or one board because I need to create board that the numbers and mines should appear. However, player must see close one and I decided that usage one board but when the game start, player see hiden board. I would like the write this game is different from standart. In standart minesweeper game, array defined by programmer like 10x10 is beginner, 20x20 is advance. However, in my game, players will choose own board size and after ever game the information about game (game result, board sizes etc.). The aim of the this approach is that players can improve themself. For example, firstly, player stared the 5x5 board and if s/he lost game, s/he can play again until the win the game. İf player won the game, s/he can increase the size of board and continue the game so that player can manage own achievement.

HOW WORKS THE CODE

g++ -std=c++11 UserInterface.cpp Cell.cpp Board.cpp Main.cpp 
