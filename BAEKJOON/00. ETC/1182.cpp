#include <iostream>
using namespace std;

int N;
int S;
int arr[21];
int cnt;	//부분수열의 개수
int sum;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void func(int k) {
	if (k == N) return;

	sum += arr[k];
	if (sum == S) cnt++;
	func(k + 1);
	sum -= arr[k];

	func(k + 1);
}

int main(void) {

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	func(0);

	cout << cnt;

	return 0;
}