#include <iostream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; //시험 본 과목의 개수
	cin >> N;

	double* arr = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int biggest = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] > biggest) {
			biggest = arr[i];
		}
	}

	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] / biggest * 100;
	}

	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}

	double avg = sum / N;

	cout << avg;

	return 0;
}