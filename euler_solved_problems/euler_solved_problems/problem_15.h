#pragma once
#include <iostream>

int problem_15() {
	const int gridSize = 20;
	long long grid[gridSize + 1][gridSize + 1];

	for (int i = 0; i < gridSize; i++) {
		grid[i][gridSize] = 1;
		grid[gridSize][i] = 1;
	}
	for (int i = gridSize - 1; i >= 0; i--) {
		for (int j = gridSize - 1; j >= 0; j--) {
			grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
		}
	}
	std::cout << grid[0][0];
	return 1;
}