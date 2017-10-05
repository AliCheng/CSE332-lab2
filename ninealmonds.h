#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
//define a gamepiece struct
struct game_piece {
	string name;
	string display;
};

//set the properties for the game
class NineAlmondsGame {
public:
	NineAlmondsGame();
	friend ostream& operator<< (ostream &out, NineAlmondsGame &game);
	int valid(unsigned int &s, unsigned int &e);
	bool done();
	bool stalemate();
	bool specificstalemate(unsigned int &e);
	int prompt(unsigned int &x, unsigned int &y);
	int turn();
	int play();
private:
	vector<game_piece> pieces;
	unsigned int column;
	unsigned int row;
};



enum forboard
{
	height = 5,
	width = 5,
	num = height*width,
	center = (num - 1) / 2,
	centerx = width / 2 + 1,
   centery = height / 2 + 1
};

enum cood
{
	//the number represent if the coords are successfully get
	correctcoords = 0,
	invalidcoords = 1,
};
enum move {
	//number to determine if the move is successful
	validmove = 0,
	quit = 1,
	nostart = 2,
	distancewrong = 3,
	gotendalmond = 4,
	nomidalmond = 5,
	novalidmove = 6,
	na_n = 7,

};
enum play{
	//determine if the game is successfully played
	successend = 0,
	badend = 1,
};
