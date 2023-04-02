#include <iostream>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		cout << str[0] << str[str.length() - 1] << "\n";
	}

	return 0;
}