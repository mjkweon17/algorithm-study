#include <iostream>
using namespace std;

int main(void) {

	int N;
	cin >> N;
	int temp;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		temp = arr[i];
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < temp) {
				arr[i] = arr[j];
				arr[j] = temp;
				temp = arr[i];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}