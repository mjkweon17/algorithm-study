#include <iostream>
using namespace std;

int main(void) {

	int X;
	cin >> X;

	int n = 0; //차수
	int accumulated = 0; //n번째 차수까지 누적된 분수들의 개수
	int numerator;	//분자
	int denominator;	//분모

	while (true) {
		n++;
		accumulated += n;
		if (accumulated >= X) {
			break;
		}
	}

	if (n % 2) {	//홀수
		numerator = accumulated - X + 1;
		denominator = n + 1 - numerator;
	}
	else {	//짝수
		denominator = accumulated - X + 1;
		numerator = n + 1 - denominator;
	}

	cout << numerator << '/' << denominator;

	return 0;
}