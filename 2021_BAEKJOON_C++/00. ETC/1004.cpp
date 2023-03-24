#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int T;	//�׽�Ʈ ���̽�
	cin >> T;

	int start[2];	//������� ��ǥ
	int end[2];		//�������� ��ǥ

	int n;	//�༺���� ����

	int count;	//�༺�� ����, ��Ż Ƚ��

	for (int i = 0; i < T; i++) {

		count = 0;

		cin >> start[0] >> start[1] >> end[0] >> end[1];

		cin >> n;

		int** planet = new int* [n];	//�༺�� ���� ������ �޸� �Ҵ�
		for (int j = 0; j < n; j++) {
			planet[j] = new int[3];
		}

		for (int j = 0; j < n; j++) {
			cin >> planet[j][0] >> planet[j][1] >> planet[j][2];	//�༺�� �߽� ��ǥ, ������ �Է�
		}

		for (int j = 0; j < n; j++) {
			double distance_s_p;	//������� �༺ ������ �Ÿ�
			double distance_e_p;	//�������� �༺ ������ �Ÿ�

			distance_s_p = sqrt((start[0] - planet[j][0]) * (start[0] - planet[j][0]) 
			+ (start[1] - planet[j][1]) * (start[1] - planet[j][1]));
			distance_e_p = sqrt((end[0] - planet[j][0]) * (end[0] - planet[j][0])
				+ (end[1] - planet[j][1]) * (end[1] - planet[j][1]));

			if (distance_s_p > planet[j][2] && distance_e_p < planet[j][2])
				count++;
			else if (distance_s_p < planet[j][2] && distance_e_p > planet[j][2])
				count++;
		}

		cout << count << endl;

		for (int i = 0; i < n; i++) {	//�༺�� ���� ����� �޸� ����
			delete[]planet[i];
		}
		delete[]planet;
	}

	return 0;
}