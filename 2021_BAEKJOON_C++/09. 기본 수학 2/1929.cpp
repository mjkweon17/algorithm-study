#include <iostream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(NULL);	//6~8번째 줄 쓰지 않으면 시간초과 뜸;;;
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;	//범위 M~N
	cin >> M >> N;

	bool* PrimeArray = new bool[N + 1];	//에라스토테네스의 체

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