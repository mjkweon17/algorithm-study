#include <iostream>
using namespace std;

int main(void) {

	int a, b;

	cin >> a >> b;
	if (a <= 0 || a >= 10 || b <= 0 || b >= 10) {
		return 0;
	}

	cout << fixed; //�Ҽ����� �������� ���
	cout.precision(15); //�Ҽ��� 15�ڸ����� ���. ���� fixed�� ���� �ʾҴٸ� �Ҽ����� ������ 15�ڸ� ���
	cout << (double)a / b;
	cout.unsetf(ios::fixed); //�Ҽ��� ���� ����

	return 0;
}