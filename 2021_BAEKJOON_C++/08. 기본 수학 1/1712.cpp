#include <iostream>
using namespace std;

int main(void) {

	int A, B, C;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << -1;
		return 0;
	}

	int break_even_point = 0;
	break_even_point = A / (C - B) + 1;

	cout << break_even_point;

	return 0;
}