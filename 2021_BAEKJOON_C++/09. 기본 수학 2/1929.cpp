#include <iostream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(NULL);	//6~8��° �� ���� ������ �ð��ʰ� ��;;;
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;	//���� M~N
	cin >> M >> N;

	bool* PrimeArray = new bool[N + 1];	//�������׳׽��� ü

	fill_n(PrimeArray, N + 1, true);
	PrimeArray[0] = PrimeArray[1] = false;

	for (int i = 2; i * i <= N; i++) {
		if (PrimeArray[i]) {
			for (int j = i * i; j <= N; j += i) {
				PrimeArray[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (PrimeArray[i]) {
			cout << i << '\n';
		}
	}

	delete[]PrimeArray;

	return 0;
}