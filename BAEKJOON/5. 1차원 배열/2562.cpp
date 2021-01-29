#include <iostream>
using namespace std;

int main(void) {

	int arr[9] = { 0 };

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	int biggest = arr[0];
	int index = 1;

	for (int i = 1; i < 9; i++) {
		if (arr[i] > biggest) {
			biggest = arr[i];
			index = i + 1;
		}
	}
	
	cout << biggest << '\n' << index;

	return 0;
}