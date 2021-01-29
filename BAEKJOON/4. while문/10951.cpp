#include <iostream>
using namespace std;

int main(void) {

	int A, B;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> A >> B) {
		cout << A + B << '\n';
	}

	return 0;
}