#include <iostream>
using namespace std;

int babylonian(int distance);

int main(void) {

	int T;	//테스트 케이스
	cin >> T;

	int* x = new int[T];
	int* y = new int[T];
	int* count = new int[T];

	for (int i = 0; i < T; i++) {

		cin >> x[i] >> y[i];
		int distance = y[i] - x[i];

		count[i] = 0;	//이동 횟수

		int n = babylonian(distance); //최대 이동 거리

		count[i] += 2 * n - 1;

		int left = distance - n * n;

		if (left > n) {
			count[i] += 2;
		}
		else if (left <= n && left > 0) {
			count[i] += 1;
		}
	}

	for(int i = 0; i < T; i++){
		cout << count[i] << endl;
	}

	return 0;
}

int babylonian(int distance) {
	int x = distance;
	int y = 1;
	while (x > y) {
		x = (x + y) / 2;
		y = distance / x;
	}
	return x;
}