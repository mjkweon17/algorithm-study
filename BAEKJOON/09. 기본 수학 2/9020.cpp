#include <iostream>
using namespace std;

int main(void) {

	int T;
	cin >> T;

	int* n = new int[T];

	//테스트 케이스 입력
	for (int i = 0; i < T; i++) {
		cin >> n[i];
	}

	//가장 큰 테스트 케이스 구하고 그 수의 소수 구하기
	int biggest = n[0];
	for (int i = 1; i < T; i++) {
		if (biggest < n[i]) {
			biggest = n[i];
		}
	}

	bool* primeArr = new bool [biggest + 1];
	fill_n(primeArr, biggest + 1, true);
	primeArr[0] = primeArr[1] = false;

	for (int i = 2; i * i <= biggest; i++) {
		if (primeArr[i]) {
			for (int j = i * i; j <= biggest; j += i) {
				primeArr[j] = false;
			}
		}
	}
	
	//각 테스트 케이스에 대하여 파티션 구하기
	int partition1, partition2;

	for (int i = 0; i < T; i++) {
		partition1 = 0;
		partition2 = n[i];

		for (int j = 2; j <= n[i] / 2; j++) {
			if (primeArr[j]) {
				if (primeArr[n[i] - j]) {
					if (n[i] - j - j < partition2 - partition1) {
						partition1 = j;
						partition2 = n[i] - j;
					}
				}
			}
		}
		cout << partition1 << " " << partition2 << endl;
	}

	delete[]primeArr;
	delete[]n;

	return 0;
}