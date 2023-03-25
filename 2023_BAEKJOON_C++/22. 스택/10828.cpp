#include <iostream>
#include <string>
#include <vector>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int line;
	cin >> line;

	vector<int> vec;

	for (int i = 0; i < line; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int num;
			cin >> num;
			vec.push_back(num);
		}
		else if (order == "pop") {
			if (vec.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << vec.back() << endl;
				vec.pop_back();
			}
		}
		else if (order == "size") {
			cout << vec.size() << endl;
		}
		else if (order == "empty") {
			if (vec.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (order == "top") {
			if (vec.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << vec.back() << endl;
			}
		}
	}

	return 0;
}