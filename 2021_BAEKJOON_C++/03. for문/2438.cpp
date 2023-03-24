#include <iostream>
using namespace std;

int main(void) {

	int N;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}