#pragma once

#include <iostream>
#include <string>

using namespace std;

class Misc
{
public:
	Misc();
	~Misc();

	//static string BuildArrow(string charater, string endCharater, int length) {
	//	string result = "";
	//	for (int i = 0; i < length; i++) {
	//		result.append(charater);
	//	}
	//	//std::cout << result << std::endl;
	//	return result.append(endCharater);
	//}
};


static string BuildArrow(string charater, string endCharater, int length) {
	string result = "";
	for (int i = 0; i < length; i++) {
		result.append(charater);
	}
	return result.append(endCharater);
}
