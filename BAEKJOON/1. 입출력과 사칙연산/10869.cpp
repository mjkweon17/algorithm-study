#include <iostream>
using namespace std;

int main(void) {

	int a, b;

	while (true) {
		cin >> a >> b;
		if (a >= 1 && a <= 10000 && b >= 1 && b <= 100000)
			break;
	}

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;

	return 0;
}