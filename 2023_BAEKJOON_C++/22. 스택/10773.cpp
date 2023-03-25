#include <iostream>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	int K;
	cin >> K;

	stack <int> S;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0) {
			S.pop();
		}
		else {
			S.push(num);
		}
	}

	int sum = 0;
	while (!S.empty()) {
		sum += S.top();
		S.pop();;
	}
	cout << sum;

	return 0;
}