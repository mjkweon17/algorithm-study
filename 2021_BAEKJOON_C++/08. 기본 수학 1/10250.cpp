#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int T;
	cin >> T; //�׽�Ʈ ���̽�

	int H, W, N; //ȣ���� �� ��, �� ���� �� ��, �� ��° �մ�
	int floor;	//����
	int num;	//ȣ��

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		num = ceil((double)N / H);
		if (N % H) {
			floor = N - (num - 1) * H;
		}
		else {
			floor = H;
		}
		cout << floor;
		cout.fill('0');
		cout.width(2);
		cout << num << endl;;
	}

	return 0;
}