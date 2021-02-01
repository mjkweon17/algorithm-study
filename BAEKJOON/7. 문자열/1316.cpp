#include <iostream>
using namespace std;

bool is_group_word(string str);

int main(void) {

	int N;
	cin >> N;

	string* str = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		if (is_group_word(str[i])) {
			count++;
		}
	}

	cout << count;

	return 0;
}

bool is_group_word(string str) {

	int arr[26] = { 0, };

	for (int i = 0; i < str.length(); i++) {
		if (arr[str[i] - 'a'] != 0) {
			if (str[i - 1] != str[i]) {
				return false;
			}
		}
		arr[str[i] - 'a']++;
	}

	return true;
}