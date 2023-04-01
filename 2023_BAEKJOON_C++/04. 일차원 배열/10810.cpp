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
	for (int i = 0; i < M; i++) {
		int j, k, l;
		cin >> j >> k >> l;
		for (j; j <= k; j++) {
			basket[j] = l;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << basket[i] << " ";
	}


	return 0;
}