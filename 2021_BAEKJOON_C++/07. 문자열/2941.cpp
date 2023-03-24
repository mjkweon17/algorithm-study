#include <iostream>
using namespace std;

int main(void) {

	string str;
	cin >> str;

	int count = 0;

	for (int i = 0; i < str.length(); i++) {
		count++;
		if (str[i] == '=') {
			if (i < 2) {
				count--;
			}
			else if (str[i - 1] == 'z' && str[i - 2] =='d') {
				count -= 2;
			}
			else {
				count--;
			}
		}
		else if (str[i] == '-') {
			count--;
		}
		else if (str[i] == 'j') {
			if (str[i - 1] == 'l' || str[i - 1] == 'n')
				count--;
		}
	}

	cout << count;

	return 0;
}