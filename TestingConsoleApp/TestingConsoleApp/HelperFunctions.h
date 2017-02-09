#pragma once

#include <ctime>

using namespace std;

int RandInt(int min, int max) {
	int result, loops = 0;
	result = (rand() % max) + 1;

	while (result < min) {
		loops++;
		result = (rand() % max) + 1;
	}

	cout << loops << " loops" << endl;
	return result;
}

int RandInt(int max) {
	return (rand() % max) + 1;
}

void StartRandom() {
	srand(time(NULL));
}