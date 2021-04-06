#include <iostream>
using namespace std;

int N;
int num[11];
int oper[4];
int cur;
int biggest = -1000000000;
int smallest = 1000000000;
int temp[11];	//나누기 연산할 때 연산 전 값 저장
int index;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void func(int k) {
	if (k == 0) {
		cur += num[0];
	}
	if (k == N - 1) {
		if (cur > biggest) {
			biggest = cur;
		}
		if (cur < smallest) {
			smallest = cur;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!oper[i]) continue;	//연산자가 존재하지 않음

		oper[i]--;
		switch (i) {
		case 0:
			cur += num[k + 1];
			func(k + 1);
			cur -= num[k + 1];
			break;
		case 1:
			cur -= num[k + 1];
			func(k + 1);
			cur += num[k + 1];
			break;
		case 2:
			cur *= num[k + 1];
			func(k + 1);
			cur /= num[k + 1];
			break;
		case 3:
			temp[index] = cur;
			index++;
			cur /= num[k + 1];
			func(k + 1);
			index--;
			cur = temp[index];
			break;
		}
		oper[i]++;
	}
}

int main(void) {

	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	func(0);

	cout << biggest << '\n';
	cout << smallest;

	return 0;
}