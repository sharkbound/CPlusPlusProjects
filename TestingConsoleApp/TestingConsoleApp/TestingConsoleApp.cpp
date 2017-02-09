// TestingConsoleApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "HelperFunctions.h"
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	StartRandom();

	cout << "Press any key to exit..." << endl;
	getch();
	return 0;
}

