#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {

	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//1. ������ ���
	double total = 0;
	for (int i = 0; i < N; i++) {
		total += arr[i];
	}
	double avg = total / N;
	cout << (int)round(avg) << endl;

	//2. �߾Ӱ� ���
	sort(arr, arr + N);
	cout << arr[N / 2] << endl;

	//3. �ֺ� ���. ���� �ֺ��� �������� �� ��°�� ���� �� ���
	//(1) �� ������ �󵵼� ���ϱ�
	int counting[8002] = { 0, };	
	for (int i = 0; i < N; i++) {
		counting[arr[i] + 4000]++;	//index 0: -4000, index 4000: 0, index 8000: 4000
	}

	//(2) �ֺ��� �� ���ϱ�
	int max = counting[0];
	for (int i = 1; i < 8002; i++) {
		if (counting[i] > max) {
			max = counting[i];
		}
	}

	//(3) �ֺ��� ���� ���ϱ�
	int count = 0;
	for (int i = 0; i < 8002; i++) {
		if (counting[i] == max) {
			count++;
		}
		if (count > 1) {
			cout << i - 4000 << endl;
			break;
		}
	}

	//(4) �ֺ� ����ϱ�
	if (count == 1) {
		for (int i = 0; i < 8002; i++) {
			if (counting[i] == max) {
				cout << i - 4000 << endl;
				break;
			}
		}
	}

	//4. ���� ���
	cout << arr[N - 1] - arr[0];

	delete[] arr;

	return 0;
}