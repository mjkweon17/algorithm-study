#include <iostream>
using namespace std;

int n, m;
int arr[10];

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void func(int k, int previous) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = previous; i <= n; i++) {
		arr[k] = i;
		func(k + 1, i);
	}
}

int main(void) {

	init();

	cin >> n >> m;
	func(0, 1);

	return 0;
}