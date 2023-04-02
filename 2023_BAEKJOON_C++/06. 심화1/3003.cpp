#include <iostream>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	int full[6] = { 1, 1, 2, 2, 2, 8 };
	int have[6];
	for (int i = 0; i < 6; i++) {
		cin >> have[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << full[i] - have[i] << " ";
	}

	return 0;
}