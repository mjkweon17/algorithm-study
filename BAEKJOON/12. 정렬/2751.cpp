#include <iostream>
#include <algorithm>
using namespace std;

//sort()는 퀵 정렬을 기반으로 구현됨
//퀵 정렬의 평균 시간복잡도는 O(n log n)이지만 최악의 경우에는 O(n^2)임
//따라서 웬만하면 sort()말고 힙 정렬이나 병합 정렬 알고리즘을 사용하자

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