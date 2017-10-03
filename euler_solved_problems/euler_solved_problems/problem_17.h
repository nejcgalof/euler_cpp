#pragma once
#include <iostream>
#include <math.h>
#include <iomanip> 
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

double problem_17() {
	string units[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	string tens1[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	string tens[] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	string hundred = "hundred";
	string thousand = "onethousand";

	int counter = 0;
	for (int number = 0; number < 1000; number++) {
		string str_number = to_string(number);
		while (str_number.length() > 0) {
			if (str_number.length() == 1 && str_number[0] != '0') {
				counter += units[str_number[0] - '0' - 1].length();
			}
			else if (str_number.length() == 2 && str_number[0] != '0') {
				if (stoi(str_number) < 20 && stoi(str_number) > 10) {
					str_number.erase(0, 1);
					counter += tens1[str_number[0] - '0' - 1].length();
				}
				else {
					counter += tens[str_number[0] - '0' - 1].length();
				}
			}
			else if (str_number.length() == 3 && str_number[0] != '0') {
				counter += units[str_number[0] - '0' - 1].length() + hundred.length();
				if (str_number[1] == '0' && str_number[2] == '0') {
				}
				else {
					counter += 3;
				}
			}
			str_number.erase(0, 1);
		}
	}
	counter += thousand.length();
	return counter;
}