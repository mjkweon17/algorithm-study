#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int N;
	cin >> N;

	int stack[10000];
	int size = 0;

	char temp[20];
	int digit = 0;
	int num;

	cin.ignore();

	string inst;
	for (int i = 0; i < N; i++) {
		getline(cin, inst, '\n');
		if (inst == "pop") {
			if (!size) {
				cout << -1 << '\n';
			}
			else {
				size--;
				cout << stack[size] << '\n';
			}
		}
		else if (inst == "size") {
			cout << size << '\n';
		}
		else if (inst == "empty") {
			if (!size) {
				cout << '1' << '\n';
			}
			else {
				cout << '0' << '\n';
			}
		}
		else if (inst == "top") {
			if (!size) {
				cout << "-1" << '\n';
			}
			else {
				cout << stack[size - 1] << '\n';
			}
		}
		else {	//push
			num = 0;
			int digit = inst.length() - 5;
			for (int i = 0; i < digit; i++) {
				temp[i] = inst[5 + i];
			}
			for (int i = 0; i < digit; i++) {
				num += (temp[i] - '0') * pow(10, digit - 1 - i);
			}
			stack[size] = num;
			size++;
		}
	}

	return 0;
}