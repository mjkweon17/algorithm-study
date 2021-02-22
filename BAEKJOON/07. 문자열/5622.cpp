#include <iostream>
using namespace std;

int alpha_to_num(char c);

int main(void) {

	string str;
	cin >> str;

	int time = 0;

	for (int i = 0; i < str.length(); i++) {
		time += alpha_to_num(str[i]) + 1;
	}

	cout << time;

	return 0;
}

int alpha_to_num(char c) {
	if (c <= 'C')
		return 2;
	else if (c <= 'F')
		return 3;
	else if (c <= 'I')
		return 4;
	else if (c <= 'L')
		return 5;
	else if (c <= 'O')
		return 6;
	else if (c <= 'S')
		return 7;
	else if (c <= 'V')
		return 8;
	else
		return 9;
}