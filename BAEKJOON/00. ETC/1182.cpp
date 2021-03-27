#include <iostream>
#include <cmath>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int n, s;	//n: 수열에 있는 정수의 개수, s: 더한 값
int cnt = 0;	//조건을 만족하는 부분 수열의 개수

int arr[20];
bool isused[20];

void func(int sum, int k) {
	if (sum == s) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused[i]) continue;

		if(abs(arr[i] + sum - s))

	}

}

int main(void) {

	init();

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);

	cout << cnt;

	return 0;
}