#pragma once

std::map<char, int> character;

void declare_characters() {
	character['A'] = 1;
	character['B'] = 2;
	character['C'] = 3;
	character['D'] = 4;
	character['E'] = 5;
	character['F'] = 6;
	character['G'] = 7;
	character['H'] = 8;
	character['I'] = 9;
	character['J'] = 10;
	character['K'] = 11;
	character['L'] = 12;
	character['M'] = 13;
	character['N'] = 14;
	character['O'] = 15;
	character['P'] = 16;
	character['Q'] = 17;
	character['R'] = 18;
	character['S'] = 19;
	character['T'] = 20;
	character['U'] = 21;
	character['V'] = 22;
	character['W'] = 23;
	character['X'] = 24;
	character['Y'] = 25;
	character['Z'] = 26;
}

unsigned long long problem_22() {
	declare_characters();
	std::ifstream file("problem_22.txt");
	std::vector<std::string> v;
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {   // get a whole line
			line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
			std::stringstream ss(line);
			while (getline(ss, line, ',')) {
				v.push_back(line);
			}
		}
	}
	std::sort(v.begin(), v.end());
	unsigned long long u = 0;
	for (int i = 0; i<v.size(); i++) {
		long sum = 0;
		for (int k = 0; k < v[i].size(); k++) {
			auto search = character.find(v[i][k]);
			if (search != character.end()) {
				sum += search->second;
			}
		}
		u += sum*(i+1);
	}
	return u;
}