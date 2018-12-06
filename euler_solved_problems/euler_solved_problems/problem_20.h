#pragma once
#include <vector>
#include <iostream>

// return factorial
std::vector<unsigned int> factorial(unsigned int maxFactor)
{
	std::vector<unsigned int> result = { 1 };

	for (unsigned int factor = 2; factor <= maxFactor; factor++)
	{
		unsigned int carry = 0;
		for (auto& digit : result)
		{
			digit = digit * factor + carry;

			if (digit >= 10)
			{
				carry = digit / 10;
				digit %= 10;
			}
			else
				carry = 0;
		}

		while (carry != 0)
		{
			result.push_back(carry % 10);
			carry /= 10;
		}
	}
	return result;
}

unsigned int problem_20() {
	unsigned int sum = 0;
	for (auto i : factorial(100)) {
		sum += i;
	}
	return sum;
}