#include <iostream>
using namespace std;

int main(void) {

	int T;	//Test Case
	cin >> T;
	
	int floor, room; //��, ȣ
	//���� floor�� k��, room�� n���� rename. 
	//floor�� 0����, room�� 1���� ����

	for (int i = 0; i < T; i++) {

		cin >> floor >> room;

		//floor�� 1�����ֱ�. �ֳ��ϸ�, 0������ �����ϱ� ������ n��° floor�� n+1��° ���� �ٸ��� ����
		floor++;

		//arr[floor][room]�� ���� �迭�� �����Ҵ��ϱ�
		int** arr = new int* [floor];
		for (int i = 0; i < floor; i++) {
			arr[i] = new int[room];
		}

		//0���� �ִ� ��� ���� i + 1������ �ʱ�ȭ
		for (int i = 0; i < room; i++) {
			arr[0][i] = i + 1;
		}
		//1ȣ�� �ִ� ��� ���� 1������ �ʱ�ȭ
		for (int i = 0; i < floor; i++) {
			arr[i][0] = 1;
		}

		//������ ȣ���� ���� arr[i - 1][j] + arr[i][j-1]�� �ʱ�ȭ
		for (int i = 1; i < floor; i++) {
			for (int j = 1; j < room; j++) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		//cout << arr[i][j]
		cout << arr[floor - 1][room - 1] << endl;

		//�����Ҵ� �޸� �����ϱ�
		for (int i = 0; i < floor; i++) {
			delete[] arr[i];
		}
		delete[]arr;
	}

	return 0;
}