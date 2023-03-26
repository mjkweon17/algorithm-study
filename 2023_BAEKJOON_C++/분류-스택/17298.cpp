#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int seq[1000000];
int ans[1000000];

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	stack<int> S;
	for (int i = N - 1; i >= 0; i--) {

		while (!S.empty() && S.top() <= seq[i]) {
			S.pop();
		}

		if (S.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = S.top();
		}

		S.push(seq[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}