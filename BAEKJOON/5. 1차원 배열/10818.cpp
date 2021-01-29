#include <iostream>
using namespace std;

int main(void) {

	int N;

	cin >> N;
	int* arr = new int[N];

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int biggest = arr[0];
	int smallest = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] > biggest) {
			biggest = arr[i];
		}
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
		}
	}

	cout << smallest << " " << biggest;

	delete[]arr;

	return 0;
}