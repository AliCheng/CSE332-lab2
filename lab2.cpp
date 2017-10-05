// lab2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ninealmonds.h"
#include "lab2header.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != expect) {
		return(message(argv[programname], argumentnumerror));
	}
	else if (string(argv[projectname]) != "NineAlmonds") {
		return(message(argv[programname], gamenameerror));
	}
	NineAlmondsGame game;
	int gameplay = game.play();
	return gameplay;
}

int message(string a,int error)
{   cout << "usage: " << a;
	cout << " NineAlmonds" << endl;
	if (error == expect) {
		return numerror;
	}
	else {
		return gamenameerror;
	}
}