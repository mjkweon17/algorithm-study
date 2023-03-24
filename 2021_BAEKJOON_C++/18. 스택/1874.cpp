#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int arr[100001];

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int n;
	stack<int> S;
	queue<char> oper;
	int cur = 1;
	bool possible = true;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (S.empty()) { 
			S.push(cur);
			cur++;
			oper.push('+');
		}

		if (S.top() > arr[i]) {
			possible = false;
			break;
		}
		else while(true) {
			if (S.top() == arr[i]) {
				arr[i] = S.top();
				S.pop();
				oper.push('-');
				break;
			}

			S.push(cur);
			cur++;
			oper.push('+');
		}
	}

	if (!possible) cout << "NO";
	else {
		for (int i = 0; !oper.empty(); i++) {
			cout << oper.front() << '\n';
			oper.pop();
		}
	}

	return 0;
}