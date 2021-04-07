#include <iostream>
using namespace std;

int arr[100001];

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int K;
	cin >> K;

	int size = 0;

	int temp;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (!temp) {
			size--;
		}
		else {
			arr[size] = temp;
			size++;
		}
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	cout << sum;

	return 0;
}