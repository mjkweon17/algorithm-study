#include <iostream>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int tower[500001];
int ans[500001];

int main(void) {

	init();

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tower[i];
	}

	stack<int> S;
	for (int i = 1; i <= N; i++) {

		while (!S.empty() && tower[S.top()] < tower[i]) {
			S.pop();
		}

		if (S.empty()) {
			ans[i] = 0;
		}
		else {
			ans[i] = S.top();
		}

		S.push(i);
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}