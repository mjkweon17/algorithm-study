#include <iostream>
#include <vector>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;

		bool isVPS = true;
		vector<char> myStack;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				myStack.push_back('(');
			}
			else if (str[j] == ')') {
				if (myStack.empty()) {
					isVPS = false;
					break;
				}
				myStack.pop_back();
			}
		}
		if (isVPS) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}