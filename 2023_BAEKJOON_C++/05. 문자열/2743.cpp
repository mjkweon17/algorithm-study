#include <iostream>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	string str;
	cin >> str;
	cout << str.length();

	return 0;
}