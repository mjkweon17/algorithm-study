#include <iostream>
using namespace std;

int main(void) {

	int N;
	cin >> N;

	string num;
	cin >> num;

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += num[i] - '0';
	}

	cout << sum;

	return 0;
}