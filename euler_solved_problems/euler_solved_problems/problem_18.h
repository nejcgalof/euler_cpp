#pragma once
#include <iostream>
#include <fstream>

void printInput(std::vector<std::vector<long long>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			std::cout << v[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

/* Each line is new vector. Each line splited with space */
std::vector<std::vector<long long>> splitInputText(std::string fileName) {
	std::ifstream ifs("problem_18.txt");
	std::vector<std::vector<long long>> input;
	if (ifs) {
		std::string line;
		while (std::getline(ifs, line)) {
			input.push_back(std::vector<long long>());
			std::stringstream split(line);
			long long value;
			while (split >> value) {
				input.back().push_back(value);
			}
		}
	}
	return input;
}

std::vector<std::vector<long long>> maximumPathSum(std::vector<std::vector<long long>> input) {
	for (int i = input.size() - 1; i > 0; i--) {
		for (int k = 0; k < input[i].size()-1; k++) {
			input[i - 1][k] += (input[i][k] > input[i][k + 1]) ? input[i][k] : input[i][k + 1];
		}
	}
	return input;
}

double problem_18() {
	std::vector<std::vector<long long>> input = splitInputText("problem_18.txt");
	//printInput(input);
	std::vector<std::vector<long long>> resultMaximumPathSum = maximumPathSum(input);
	//printInput(resultMaximumPathSum);
	return resultMaximumPathSum[0][0];
}