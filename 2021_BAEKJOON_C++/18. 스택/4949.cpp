#include <iostream>
#include <string>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool is_balanced(string& str) {
	
	char temp;

	stack<char> S;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '[') {
			S.push('[');
		}
		else if (str[i] == '(') {
			S.push('(');
		}
		else if (str[i] == ']') {
			if (S.empty()) return false;
			temp = S.top();
			if (temp != '[') return false;
			S.pop();
		}
		else if (str[i] == ')') {
			if (S.empty()) return false;
			temp = S.top();
			if (temp != '(') return false;
			S.pop();
		}
	}

	if (!S.empty()) return false;
	else return true;
}

int main(void) {

	init();

	string str;

	while (true) {

		getline(cin, str);
		
		if (str == ".") return 0;

		if (is_balanced(str)) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}