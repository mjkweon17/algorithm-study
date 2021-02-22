#include <iostream>
using namespace std;

int main(void) {

	int N;	//카드의 개수
	int M;	//딜러가 외친 숫자
	cin >> N >> M;

	int* card = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	int total = 0;	//선택한 3장의 카드의 합

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum == M) {
					total = sum;
					break;
				}
				if (sum > total && sum <= M) {
					total = sum;
				}
			}
		}
	}

	cout << total;

	return 0;
}