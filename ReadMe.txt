Alison Cheng Lab2


I was fortune enought that I didn't encounter any problem
My Trial:
if only input lab2.exe,
got usage: H:\my documents\visual studio 2015\projects\lab2.exe NineAlmonds
which is the right thing we should enter
if input lab2.exe NineAlmonds
got:

4

3   A A A

2   A A A

1   A A A

0

x 0 1 2 3 4
If you want to continue, enter coordinate x,y , if you want to quit, enter quit:

which is my gameboard

if input wrong format coordinates, like a,b
output: 4

3   A A A

2   A A A

1   A A A

0

x 0 1 2 3 4
If you want to continue, enter coordinate x,y , if you want to quit, enter quit: a,b
Wrong format
If you want to continue, enter coordinate x,y , if you want to quit, enter quit:

if input coordinates bigger than the board,
output:
4

3   A A A

2   A A A

1   A A A

0

x 0 1 2 3 4

If you want to continue, enter coordinate x,y , if you want to quit, enter quit: 9,1
Coordinates out of bound

if we successfully finish the game follow the instructions on the CSE332 Website 
output:
4

3

2     A

1

0

x 0 1 2 3 4

0,2 to 2,2

Cong! You've Win the Game!. Turns:4

if there is no valid move anymore:

4     A

3

2       A

1   A

0

x 0 1 2 3 4

2,2 to 2,4 to 4,2 to 2,0 to 2,2 to 0,2 to 2,4

you can't continue this turn because there is no valid movement on the selected almond, start a new turn now
Sorry You Get Stuck, No Valid Movement Anymore. Turns:2



========================================================================
    CONSOLE APPLICATION : lab2 Project Overview
========================================================================

AppWizard has created this lab2 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab2 application.


lab2.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab2.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab2.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab2.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
