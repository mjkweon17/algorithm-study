#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10001] = { 0, };

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[input]++;
	}

	int index = 0;
	for (int i = 0; i < 10001; i++) {
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
				index++;
			}
		}
		if (index == N) {
			break;
		}
	}

	return 0;
}