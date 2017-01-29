// FirstC++ConsoleApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "FileManager.h"
#include <string>
#include <stdio.h>
#include "dirent.h"
#include "Misc.h"
#include <conio.h>

using namespace std;

//#define SSTR( x ) static_cast< std::ostringstream & >( \
//        ( std::ostringstream() << std::dec << x ) ).str()

void print(char text)
{
	cout << text << endl;
}

void print(char* text)
{
	cout << text << endl;
}

int main()
{
	char* userInput;
	FileManager fm;
	fm.PrintDirTree(".", 0, 0);
	getch();
}

