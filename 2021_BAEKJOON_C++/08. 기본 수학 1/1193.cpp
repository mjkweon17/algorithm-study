#include <iostream>
using namespace std;

int main(void) {

	int X;
	cin >> X;

	int n = 0; //����
	int accumulated = 0; //n��° �������� ������ �м����� ����
	int numerator;	//����
	int denominator;	//�и�

	while (true) {
		n++;
		accumulated += n;
		if (accumulated >= X) {
			break;
		}
	}

	if (n % 2) {	//Ȧ��
		numerator = accumulated - X + 1;
		denominator = n + 1 - numerator;
	}
	else {	//¦��
		denominator = accumulated - X + 1;
		numerator = n + 1 - denominator;
	}

	cout << numerator << '/' << denominator;

	return 0;
}