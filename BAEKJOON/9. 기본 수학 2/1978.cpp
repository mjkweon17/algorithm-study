#include <iostream>
using namespace std;

int main(void) {

	int N;	//입력받을 숫자의 개수
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int count = 0;
	int is_prime = 0;

	for (int i = 0; i < N; i++) {

		if (arr[i] == 1) {
			continue;
		}
		else if (arr[i] == 2) {
			count++;
			continue;
		}

		is_prime = 0;

		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				is_prime = 1;
				break;
			}
		}

		if (is_prime == 0) {
			count++;
		}
	}

	cout << count;

	return 0;
}