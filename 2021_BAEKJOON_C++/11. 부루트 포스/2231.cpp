#include <iostream>
using namespace std;

int getSum(int num);

int main(void) {

	int N;
	cin >> N;

	bool haveSum = false;

	for (int i = 1; i < N; i++) {
		if (getSum(i) == N) {
			cout << i;
			haveSum = true;
			break;
		}
	}

	if (!haveSum) {
		cout << 0;
	}

	return 0;
}

int getSum(int num) {

	int sum = num;

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}