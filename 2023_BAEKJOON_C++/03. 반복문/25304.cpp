#include <iostream>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	int X;	//�������� ���� �� �ݾ�
	int N;	//������ ������ ������ ��
	cin >> X;
	cin >> N;

	int sum = 0;
	int a, b;	//������ ����, ����
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == X) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}