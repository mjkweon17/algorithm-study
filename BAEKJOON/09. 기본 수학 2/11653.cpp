#include <iostream>
using namespace std;

int main(void) {

	int N;
	cin >> N;

	int divisor = 2;
	while (true) {
		if (N == 1) {
			return 0;
		}
		if (N % divisor == 0) {
			N /= divisor;
			cout << divisor << endl;
		}
		else {
			divisor++;
		}
	}

	return 0;
}