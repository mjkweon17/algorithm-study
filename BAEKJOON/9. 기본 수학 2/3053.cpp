#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int R;
	cin >> R;

	const double pi = atan(1) * 4;

	cout << fixed;
	cout.precision(6);

	cout << R * R * pi << endl;
	cout << R * R * 2.0;

	return 0;
}