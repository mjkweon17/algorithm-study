#include <iostream>
using namespace std;

int main(void) {

	int x, y;	//�� ��ġ
	int w, h;	//������ �� ������
	cin >> x >> y >> w >> h;

	int smallest = x;
	if (smallest > y) {
		smallest = y;
	}
	if (smallest > w - x) {
		smallest = w - x;
	}
	if (smallest > h - y) {
		smallest = h - y;
	}

	cout << smallest;

	return 0;
}