#include <iostream>
using namespace std;

int main(void) {

	int a, b;

	cin >> a >> b;
	if (a <= 0 || a >= 10 || b <= 0 || b >= 10)
		return 0;

	cout << a * b;

	return 0;
}