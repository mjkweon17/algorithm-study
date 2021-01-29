#include <iostream>
using namespace std;

int main(void) {

	int A, B;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> A >> B;
		if (A == 0 && B == 0) {
			return 0;
		}
		cout << A + B << '\n';
	}

	return 0;
}