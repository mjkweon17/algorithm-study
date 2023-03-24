#include <iostream>
#define RANGE 10000
using namespace std;

int self_num(int num) {
	int sum = num;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}

	if (sum > RANGE) {
		return 0;
	}
	return sum;
}

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[RANGE + 1] = { 0, };

	for (int i = 1; i <= RANGE; i++) {
		arr[self_num(i)] = 1;
	}

	for (int i = 1; i <= RANGE; i++) {
		if (!arr[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}