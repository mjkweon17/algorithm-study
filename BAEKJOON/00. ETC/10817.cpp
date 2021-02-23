#include <iostream>
using namespace std;

int main(void) {

	int A, B, C;
	cin >> A >> B >> C;

	int temp;

	while (true) {
		if (A >= B && B >= C) {
			break;
		}
		if (A < B) {
			temp = A;
			A = B;
			B = temp;
		}
		if (B < C) {
			temp = C;
			C = B;
			B = temp;
		}
	}

	cout << B;

	return 0;
}