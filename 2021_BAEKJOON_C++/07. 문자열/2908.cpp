#include <iostream>
#include <algorithm>	//reverse함수 사용을 위해 선언
using namespace std;

int main(void) {

	string num1, num2;
	cin >> num1 >> num2;

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	/*
	string reverse_num1 = num1, reverse_num2 = num2;
	for (int i = 2; i >= 0; i--) {
		reverse_num1[2 - i] = num1[i];
		reverse_num2[2 - i] = num2[i];
	}
	*/

	for (int i = 0; i <= 2; i++) {
		if (num1[i] > num2[i]) {
			cout << num1;
			break;
		}
		else if (num1[i] < num2[i]) {
			cout << num2;
			break;
		}
	}

	return 0;
}