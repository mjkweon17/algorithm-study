#include <iostream>
using namespace std;

int main(void) {

	int A, B, V;	//�ö󰡴� ����, �������� ����, ���� ����
	cin >> A >> B >> V;

	int day;

	if ((V - A) % (A - B)) {
		day = (V - A) / (A - B) + 2;
	}
	else {
		day = (V - A) / (A - B) + 1;
	}

	cout << day;

	return 0;
}