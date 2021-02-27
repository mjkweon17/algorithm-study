#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {

	long long N;
	cin >> N;
	
	int arr[10] = { 0, };

	int index = 0;
	while (N) {
		arr[index] = N % 10;
		N /= 10;
		index++;
	}
	
	sort(arr, arr + index, compare);

	for (int i = 0; i < index; i++) {
		cout << arr[i];
	}
	
	return 0;
}