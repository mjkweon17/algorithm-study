#include <iostream>
using namespace std;

int main(void) {

	int T;
	int A, B;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << '\n';
	}

	return 0;
}