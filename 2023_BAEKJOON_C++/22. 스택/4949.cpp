#include <iostream>
#include <string>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	while (true) {
		string str;
		getline(cin, str);

		if (str == ".") {
			break;
		}

		bool balanced = true;

		stack<char> S;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '[' || str[i] == '(') {
				S.push(str[i]);
			}
			else if (str[i] == ']' || str[i] == ')') {
				if (S.empty()) {
					balanced = false;
					break;
				}
				char stack_top = S.top();
				S.pop();
				if(stack_top == '[') {
					if (str[i] == ']')
						continue;
				}
				else if (stack_top == '(') {
					if (str[i] == ')')
						continue;
				}
				balanced = false;
				break;
			}
		}
		if (!S.empty()) {
			balanced = false;
		}

		if (balanced) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}