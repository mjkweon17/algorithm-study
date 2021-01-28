#include <iostream>
using namespace std;

int main(void) {

	int round;
	int a, b;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> round;

	for (int i = 0; i < round; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}