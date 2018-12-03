#pragma once
#include <iostream>
#include <numeric>
#include <vector>

long long problem_19() {
	std::vector<int> daysInMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	std::vector<int> daysInMonth2 = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	long long counterOfSundays = 0;
	int rest_days = 1; // start point 1 day away from sunday
	bool leap_year = false;
	for (int i = 1901; i < 2001; i++) { // years
		if (i % 4 == 0 && i % 400 == 0) {
			leap_year = false;
		}
		else if (i % 4 == 0) {
			leap_year = true;
		}
		else {
			leap_year = false;
		}
		if (leap_year) {
			for (int j = 0; j < daysInMonth2.size(); j++) {
				rest_days = rest_days + (daysInMonth2[j] % 7) - 1;
				if (rest_days % 7 == 0 || rest_days == 0) {
					counterOfSundays++;
					rest_days = 0;
				}
			}
		}
		else {
			for (int j = 0; j < daysInMonth.size(); j++) {
				rest_days = rest_days + (daysInMonth[j] % 7) - 1;
				if (rest_days % 7 == 0 || rest_days == 0) {
					counterOfSundays++;
					rest_days = 0;
				}
			}
		}
	}
	return counterOfSundays;
}