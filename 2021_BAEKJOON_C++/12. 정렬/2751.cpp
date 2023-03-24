#include <iostream>
#include <algorithm>
using namespace std;

//sort()�� �� ������ ������� ������
//�� ������ ��� �ð����⵵�� O(n log n)������ �־��� ��쿡�� O(n^2)��
//���� �����ϸ� sort()���� �� �����̳� ���� ���� �˰����� �������

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;
}