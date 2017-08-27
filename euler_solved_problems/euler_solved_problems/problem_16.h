#pragma once
#include <iostream>
#include <math.h>
#include <iomanip> 
#include <sstream> 

int problem_16() {
	const double pow_number = 1000;
	const double number = 2;
	double result = pow(number, pow_number);
	std::stringstream ss;
	ss.setf(std::ios::fixed);
	ss << std::setprecision(0) << result;

	int sum = 0;
	for (int i = 0; i < ss.str().length(); i++) {
		sum += (int)(ss.str()[i] - '0');
	}
	std::cout << sum;
	return 1;
}
