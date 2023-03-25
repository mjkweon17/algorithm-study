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

	int n;
	cin >> n;
	
	vector<int> myStack;
	vector<char> output;
	bool fail = false;
	int next_num = 1;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		while (num >= next_num) {
			cout << "+" << next_num << endl;
			myStack.push_back(next_num);
			next_num++;
			output.push_back('+');
		}
		if (num == myStack.back()) {
			cout << "-" << endl;
			myStack.pop_back();
			output.push_back('-');
		}
		else {
			fail = true;
			break;
		}
	}

	if (!fail) {
		for (int i = 0; i < output.size(); i++) {
			cout << output[i] << '\n';
		}
	}

	return 0;
}