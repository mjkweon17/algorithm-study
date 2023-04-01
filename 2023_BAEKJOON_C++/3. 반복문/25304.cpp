#include <iostream>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	int X;	//영수증에 적힌 총 금액
	int N;	//구매한 물건의 종류의 수
	cin >> X;
	cin >> N;

	int sum = 0;
	int a, b;	//물건의 가격, 개수
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == X) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}