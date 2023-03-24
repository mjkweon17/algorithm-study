#include <iostream>
using namespace std;

bool hansu(int num);
int digit(int num);

int main(void) {

	int N;
	cin >> N;

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (hansu(i)) {
			count++;
		}
	}

	cout << count;

	return 0;
}

bool hansu(int num) {

	if (num < 100)
		return 1;

	int is_hansu = 1;
	int digits = digit(num);
	int* arr = new int[digits];
	int count = 0;
	while (count != digits) {
		arr[count] = num % 10;
		num /= 10;
		count++;
	}
	int difference = arr[1] - arr[0];
	for (int i = 1; i < digits - 1; i++) {
		if (difference != arr[i + 1] - arr[i]) {
			is_hansu = 0;
			break;
		}
	}

	return is_hansu;
}

int digit(int num) {

	int digits = 0;

	while (num != 0) {
		num /= 10;
		digits++;
	}

	return digits;
}