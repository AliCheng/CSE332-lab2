#include "stdafx.h"
#include <string>

using namespace std;

//Arguments
enum arguments
{
	programname = 0,
	projectname = 1,
	expect = 2
};


//Errors
enum errors
{
	numerror = 1,
	gamenameerror = 2,
	argumentnumerror = 3
};


//message function 
int message(string a, int error);