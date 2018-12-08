
int sumOfAllDividors(int num) {
	int sum = 0;
	for (int i = 1; i <= sqrt(num); i++) { // all devidors are from 1 to sqrt(i
		if (num % i == 0) {
			if (num / i == i) { // if divisors are equal
				sum += i;
			}
			else {
				sum += i + (num / i); // add both numbers
			}
		}
	}
	return sum - num;
}

long problem_21() {
	long sum = 0;
	std::vector<int> mapOfd; // number[d]
	for (int i = 0; i < 10000; i++) {
		int d = sumOfAllDividors(i);
		if (mapOfd.size() > d && mapOfd[d] == i) {
			sum += d + i; // sum both numbers
		}
		mapOfd.push_back(d); // add sum of dividors for this number
	}
	return sum;
}