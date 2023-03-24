#include <iostream>
using namespace std;

int main(void) {

	int N;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = N; i >= 1; i--) {
		cout << i << '\n';
	}

	return 0;
}