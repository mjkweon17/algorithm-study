//Âü°í : https://cryptosalamander.tistory.com/39
#include <iostream>
using namespace std;

void hanoi(int num, int start, int bypass, int to);

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << (1 << N) - 1 << '\n';	// 1<<num Àº 2^num
	hanoi(N, 1, 2, 3);
}

void hanoi(int num, int start, int bypass, int to) {

	if (num == 1) {
		cout << start << " " << to << '\n';
	}
	else {
		hanoi(num - 1, start, to, bypass);
		cout << start << " " << to << '\n';
		hanoi(num - 1, bypass, start, to);
	}
}