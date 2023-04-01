#include <iostream>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int basket[101];

int main(void) {

	init();

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		basket[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int j, k;
		cin >> j >> k;
		for (int l = j; l <= (j + k) / 2; l++) {
			int temp = basket[l];
			basket[l] = basket[k - (l - j)];
			basket[k - (l - j)] = temp;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << basket[i] << " ";
	}

	return 0;
}