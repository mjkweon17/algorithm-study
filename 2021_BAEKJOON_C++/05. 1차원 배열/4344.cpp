#include <iostream>
using namespace std;

int main(void) {

	int C;
	int N;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N;
		int* score = new int[N];

		for (int i = 0; i < N; i++) {
			cin >> score[i];
		}

		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += score[i];
		}

		double average = (double)sum / N;
		
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (score[i] > average) {
				count++;
			}
		}

		cout << fixed;	//�Ҽ��� �ڸ� ����
		cout.precision(3);	//fixed ������ ���μ�+�Ҽ��� ���ļ� 3�ڸ�
		cout << (double)count / N * 100 << "%" << '\n';
		//cout.unsetf(ios::fixed);	//���� ����
	}

	return 0;
}