#include <iostream>
using namespace std;

int babylonian(long long distance);

int main(void) {

	int T;	//�׽�Ʈ ���̽�
	cin >> T;

	for (int i = 0; i < T; i++) {

		long long x, y;	//���� ��ġ, ��ǥ ��ġ
		cin >> x >> y;
		long long distance = y - x;

		int count = 0;	//�̵� Ƚ��

		int n = babylonian(distance); //�ִ� �̵� �Ÿ�
		
		count += 2 * n - 1;
		
		int left = distance - n * n;
		
		if (left > n) {
			count += 2;
		}
		else if (left > 0) {
			count += 1;
		}
		
		cout << count << endl;
	}

	return 0;
}

int babylonian(long long distance) {
	long long x = distance;
	long long y = 1;
	while (x > y) {
		x = (x + y) / 2;
		y = distance / x;
	}
	return x;
}