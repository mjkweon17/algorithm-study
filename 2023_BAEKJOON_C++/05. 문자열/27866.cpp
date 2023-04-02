#include <iostream>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	string S;
	int i;
	cin >> S >> i;
	cout << S[i - 1];

	return 0;
}