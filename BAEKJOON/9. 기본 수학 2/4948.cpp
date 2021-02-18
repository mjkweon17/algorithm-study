#include <iostream>
#define SCOPE 123456
using namespace std;

int main(void) {

	bool* primeArr = new bool [SCOPE * 2 + 1];
	fill_n(primeArr, SCOPE * 2 + 1, true);

	primeArr[1] = primeArr[0] = false;
	for (int i = 2; i * i <= SCOPE * 2; i++) {
		if (primeArr[i]) {
			for (int j = i * i; j <= SCOPE * 2; j += i) {
				primeArr[j] = false;
			}
		}
	}

	while (true) {
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}

		int count = 0;
		for (int i = N + 1; i <= N * 2; i++) {
			if (primeArr[i]) {
				count++;
			}
		}

		cout << count << endl;
	}

	delete[]primeArr;

	return 0;
}