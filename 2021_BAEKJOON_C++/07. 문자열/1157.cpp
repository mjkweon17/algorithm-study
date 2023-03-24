#include <iostream>
using namespace std;

int main(void) {

	string str;
	cin >> str;

	int arr[26] = { 0, };

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			arr[str[i] - 'A']++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			arr[str[i] - 'a']++;
		}
	}

	int most = arr[0];
	int index = 0;
	int overlap = 0;

	for (int i = 1; i < 26; i++) {
		if (most == arr[i]) {
			overlap = 1;
		}
		else if (most < arr[i]) {
			overlap = 0;
			most = arr[i];
			index = i;
		}
	}

	if (overlap) {
		cout << '?';
	}
	else {
		cout << (char)(index + 'A');
	}

	return 0;
}