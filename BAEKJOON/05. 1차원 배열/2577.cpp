#include <iostream>
#include <cmath>
using namespace std;

int get_digit(int num);

int main(void) {

	int A, B, C;
	int num[10] = { 0, };
	int result;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	result = A * B * C;

	int temp_num = result;
	int digit = get_digit(result);

	for (int i = 0; i < digit; i++) {
		int index = temp_num % 10;
		num[index]++;
		temp_num /= 10;
	}

	for (int i = 0; i <= 9; i++) {
		cout << num[i] << '\n';
	}

	return 0;
}

int get_digit(int num) {

	int digit = 0;

	while (num) {
		num /= 10;
		digit++;
	}

	return digit;
}