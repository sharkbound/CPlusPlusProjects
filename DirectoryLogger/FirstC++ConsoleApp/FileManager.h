#pragma once

#include <iostream>
#include "dirent.h"
#include "Misc.h"
#include <fstream>
#include <string>

using namespace std;


class FileManager
{
public:
	char* fname = "log.log";
	Misc m;
	ofstream logf;
	int DirLoopHighestIter = 0;
	FileManager();
	~FileManager();

	void CheckLogExist()
	{
		FILE *file = fopen(fname, "a");
	}

	void SetVariable(char *item) {
		item = "new value";
	}

	void PrintDirTree(string path, int iteration, int arrowLength) {
		DIR *folder = opendir(path.c_str());

		// if folder/directory does not exist close the connnection
		if (folder == NULL) {
			closedir(folder);
			return;
		}

		dirent *entry = readdir(folder);
		while (entry != NULL)
		{
			if (entry->d_type == DT_DIR) {
				string DirName(entry->d_name);

				// make sure the folder/directory isnt not . or ..
				// if so move onto the next folder/directory
				if (DirName.compare(".") == false || DirName.compare("..") == false)
				{
					entry = readdir(folder);
					continue;
				}
				if (iteration > DirLoopHighestIter) DirLoopHighestIter = iteration;

				//print the directory to console then move into next directory
				string logText(BuildArrow("-", ">", arrowLength) + " [" + DirName + " : " + to_string(iteration) + "]\n");
				cout << logText;
				LogToFile(logText); 
				PrintDirTree(path + "\\" + DirName, iteration + 1, arrowLength + 2);
			}
			entry = readdir(folder);
		}
		closedir(folder);
	}

	void ConnectToLogFile() {
		this->logf = ofstream("log.log");
	}

	void CloseLogFile() {
		logf.close();
	}

	void LogToFile(string msg, string prefix = " [INFO] ") {
		logf << prefix << msg;
	}
};

