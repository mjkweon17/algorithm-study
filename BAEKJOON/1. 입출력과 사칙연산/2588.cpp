#include <iostream>
using namespace std;

int main(void) {

	int a, b;

	cin >> a >> b;
	while (true) {
		if (a >= 100 && a < 1000 && b >= 100 && b < 1000)
			break;
	}

	int line3, line4, line5, line6;
	line3 = a * (b % 10);
	line4 = a * (b / 10 % 10);
	line5 = a * (b / 100);
	line6 = line3 + line4 * 10 + line5 * 100;

	cout << line3 << endl;
	cout << line4 << endl;
	cout << line5 << endl;
	cout << line6 << endl;

	return 0;
}