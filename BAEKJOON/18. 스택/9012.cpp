#include <iostream>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool is_VPS() {
	int cnt = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') cnt++;
		else if (str[i] == ')') cnt--;
		if (cnt < 0) return false;
	}
	if (!cnt) return true;
	else return false;
}

int main(void) {

	init();

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		if (is_VPS()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}