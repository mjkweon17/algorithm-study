#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void func(int k, int previous) {

	if (k == m) {	//base condition
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = previous + 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			func(k + 1, i);
			isused[i] = false;
		}
	}
}

int main(void) {

	init();
	cin >> n >> m;

	func(0, 0);

	return 0;
}