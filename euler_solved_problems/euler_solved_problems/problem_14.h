#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>

std::map<long long, long long> collatz_map;
int collatz(long long num) {
	int iter = 0;
	while (true) {
		iter++;
		if (num == 1) {
			return iter;
		}
		std::map<long long, long long>::const_iterator got = collatz_map.find(num);
		if (collatz_map.find(num) == collatz_map.end()) {
			if (num % 2 == 0) {
				num= (num / 2);
			}
			else {
				num= (3 * num) + 1;
			}
		}
		else {
			iter += got->second-1;
			return iter;
		}
	}
}

bool comp(std::pair<long long, long long> a, std::pair<long long, long long> b) {
	return a.second > b.second;
}

int problem_14() {
	for (long long i = 1; i < 1000000; i++) {
		collatz_map.insert(std::pair<long long,long long>(i, collatz(i)));
	}
	std::vector<std::pair<long long, long long>> elems(collatz_map.begin(), collatz_map.end());
	std::sort(elems.begin(), elems.end(), comp);
	std::cout << elems[0].first;
	return 1;
}