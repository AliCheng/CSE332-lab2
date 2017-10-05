#include "stdafx.h"
#include "ninealmonds.h"
#include "lab2header.h"


// the function that set the display and name for each pieces in the game
NineAlmondsGame::NineAlmondsGame() {
	game_piece piece;
	for (unsigned int i = 0; i < num; i++) {
		if((center-width-1 <=i && i<= center-width +1)|| (center- 1 <=i && i<=center + 1)|| (center + width - 1 <=i && i<=center + width + 1)){
		piece.display = "A";
		piece.name = "brown almond";
		}
		else {
			piece.display = " ";
			piece.name = "";
		}
		pieces.push_back(piece);
	}
}
//an insert operator that extract value from vector pieces and print to the board
ostream & operator<< (ostream & out, NineAlmondsGame & game) {
	//Print out the board
	game.column = width;
	game.row = height;
	string display = "x 0 1 2 3 4";
	//extract each piece from pieces and show it's display
	for ( int i = game.column-1; i >= 0; i--) {
		string line;
		out << (i);
		for (int j = game.row-1; j >= 0; j--) {
			line = " " + game.pieces[height * i + j].display + line;
		}
		out << line << endl;
		out << endl;
	}
	out << display << endl;
	return out;
}

//check the validity of a movement, take indexs as inputs
int NineAlmondsGame::valid(unsigned int &s, unsigned int &e) {
	// if the start point has an almond
	if (pieces[s].name != "") {
		unsigned int startx, starty, endx, endy;
		startx = s%width;
		starty = s / width;
		endx = e%width;
		endy = e / width;
		//if the end point got an almond
		if (pieces[e].name == "") {
			// if the distance is right
			// check the index of the middle almond
			unsigned int m = (s + e) / 2;

			if (((startx == endx) && (starty == endy + 2 || endy == starty + 2)) || ((starty == endy) && (startx == endx + 2 || endx == startx + 2)) || (((startx == endx + 2) || (startx == endx - 2)) && ((starty == endy + 2) || (starty == endy - 2)))) {
				//if the middle got an almond
				if (pieces[m].name != "") {
					return validmove;
				}
				else {
					return nomidalmond;
				}
			}
			else {
				return distancewrong;
			}
		}
		else {
			return gotendalmond;
		}
	}
	else {
		return nostart;
	}
}


//the function that check if there is any possible valid move in the board
bool NineAlmondsGame::stalemate() {
	bool ifany = false;
	//check the validity of each index
	for (unsigned int i = 0; i < num;i++) {
		for (unsigned int j = 0; j < num; j++) {
			if (valid(i, j) == validmove) {
				ifany = true;
			}
		}
	}
	if (ifany) {
		return false;
	}
	else if (done()) {
		return false;
	}
	else {
		return true;
	}
}

//check the if there is any valid move for a specifc index
bool NineAlmondsGame::specificstalemate(unsigned int&e) {
	bool ifany = false;
	//check for the index = e
	for (unsigned int j = 0; j < num; j++) {
		if (valid(e, j) == validmove) {
			ifany = true;
		}
	}
	if (ifany) {
		return false;
	}
	else {
		return true;
	}
}
//check if this game is finished 
bool NineAlmondsGame::done() {
	for (unsigned int i = 0; i < num; i++) {
		if (i == center) {
			if (pieces[i].name == "") {
				return false;
			}
		}
		else {
			if (pieces[i].name != "") {
				return false;
			}
		}
	}
	return true;
}


//prompt the user to enter two values
int NineAlmondsGame::prompt(unsigned int &x, unsigned int &y) {
	while (true) {
		cout << "If you want to continue, enter coordinate x,y , if you want to quit, enter quit: ";
		string coord;
		getline(cin, coord);
		istringstream iss(coord);
		//if user enter quit, then quit
		if (coord == "quit") {
			return quit;
		}
		//check if the second place is "," and replace it to " "
		if (coord[1]==',') {
			coord[1] = ' ';
		}
		//check if the numbers can be extract successfully
		if ((iss >> x >> y)) {
			if ((x >= 0 && x < width) && (y >= 0 && y < height)) {
				cout << "Coordinates Recorded" << endl;
				return correctcoords;
			}
			//keep prompt until we get the right coords
			else {
				cout << "Coordinates out of bound" << endl;
			}
		}
		else {
			cout << "Wrong format" << endl;
		}
	}
}

//the function to move almonds
int NineAlmondsGame::turn() {
	unsigned int startx, starty, endx, endy;
	//booleans to check if the user decide to continue with the same almond
	bool conti = false;
	bool firsttime = true;
	ostringstream output;
	int firstco;
	//check when to prompt and if the same almond still can make valid move
	while ((firsttime||conti)&&!done()&&!stalemate()) {
		if (conti == false) {
			firstco = prompt(startx, starty);
			unsigned int s = starty*width + startx;
			if (firstco == quit) {
				return quit;
			}
			if (specificstalemate(s)) {
				cout << "this start almond can't make valid move, please start a new turn"<<endl;
				return novalidmove;
			}
		}
		//ask for the end point coords
		unsigned int s = starty*width + startx;
		int nextco = prompt(endx, endy);
		// if quit ,then quit
		if (nextco == quit) {
			return quit;
		}
		//if correct, process
		else if (nextco == correctcoords) {
			unsigned int e = endy*width + endx;
			unsigned int m = (s + e) / 2;
			int ifvalid = valid(s, e);
			//the process of jump over one almond 
			if (ifvalid == validmove) {
				firsttime = false;
				pieces[s].name = "";
				pieces[s].display = " ";
				pieces[e].name = "brown almond";
				pieces[e].display = "A";
				pieces[m].name = "";
				pieces[m].display = " ";
				cout << *this << endl;
				if (!conti) {
					output << startx << "," << starty;
				}
				output << " to " << endx << ',' << endy;
				cout << output.str() << endl;

				bool ifchoice = false;
				cout << endl;
				//check if the same almond can still make valid move
				while (!ifchoice&&!done()) {
					if (specificstalemate(e)) {
						cout << "you can't continue this turn because there is no valid movement on the selected almond, start a new turn now"<<endl;
						conti = false;
						ifchoice = true;
					}
					else {
						//if can still make valid move, prompt the user if they want to use the same almond
						cout << "Continue this turn (enter y or n)?";
						string input;
						getline(cin, input);
						if (input=="y") {
							conti = true;
							ifchoice = true;							
							startx = endx;
							starty = endy;
						}
						else if (input == "n") {
							conti = false;
							ifchoice = true;
						}
					}
				}
			}
			else {
				if (ifvalid == nostart) {
					cout << "Starting square doesn't have an almond. ";
				}
				if (ifvalid == nomidalmond) {
					cout << "There is not a middle almond";
				}
				if (ifvalid == distancewrong) {
					cout << "Distance is wrong ";
				}
			    if (ifvalid == gotendalmond) {
					cout << "There is an almond on the end point";
				}
				if (conti==true) {
					cout << "Enter the second one again." << endl;
				}
				else if(conti==false) {
					cout << " Start over with the first coordinate" << endl;
				}
			}
		}
	}
	if (!firsttime) {
		return validmove;
	}
	else {
		return novalidmove;
	}
}

//play the game
int NineAlmondsGame::play() {
	int turns = 0;
	// if it's not done and not stucked
	while(!done()&&!stalemate()) {
		cout << *this;
		int a = turn();
		//quit if the users type quit
		if (a == quit) {
			cout << "You Quit. Turns:" << turns << endl;
			return quit;
			}
		turns++;
		}
	//done if the user win
	if (done()) {
		cout << "Cong! You've Win the Game!. Turns:" << turns << endl;
		return successend;
	}
	else {
		// end when there is no valid movement on the board
		cout << "Sorry You Get Stuck, No Valid Movement Anymore. Turns:" << turns << endl;
		return badend;
	}

}

