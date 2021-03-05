#include <iostream>
#include <algorithm>
using namespace std;

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

	int M;
	cin >> M;

	int* arr1 = new int[M];

	for (int i = 0; i < M; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < M; i++) {
		int start = 0;
		int end = N - 1;
		int mid;
		int	iden = 0;	//존재하는지 않는지 판정

		while (start <= end) {
			mid = (start + end) / 2;

			if (arr1[i] == arr[mid]) {
				iden = 1;
				break;
			}
			else if (arr1[i] > arr[mid]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		cout << iden << '\n';
	}

	return 0;
}