#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string str;
	getline(cin, str);

	int count_blank = 0;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			count_blank++;
		}
	}

	if (str[0] == ' ') {
		if (str[len - 1] == ' ') {
			count_blank--;
		}
	}
	else {
		if (str[len - 1] != ' ') {
			count_blank++;
		}
	}

	cout << count_blank;

	return 0;
}