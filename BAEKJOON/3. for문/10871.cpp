#include <iostream>
using namespace std;

int main(void) {

	int N;
	int X;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> X;

	int *A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (A[i] < X) {
			cout << A[i] << '\n';
		}
	}

	delete[]A;

	return 0;
}