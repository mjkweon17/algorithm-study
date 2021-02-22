#include <iostream>
using namespace std;

int main(void) {

	int N, M;
	cin >> N >> M;

	//M * N 크기의 보드 이중배열로 만들기
	char** board = new char* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];
	}

	//보드 색 입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int count = 0;
	int result = 8 * 8 / 2;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {

			//(1)
			count = 0;

			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2) {
						if (board[k][l] == 'B') {
							count++;
						}
					}
					else {
						if (board[k][l] == 'W') {
							count++;
						}
					}
				}
			}

			if (count < result) {
				result = count;
			}

			//(2)
			count = 0;

			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2) {
						if (board[k][l] == 'W') {
							count++;
						}
					}
					else {
						if (board[k][l] == 'B') {
							count++;
						}
					}
				}
			}

			if (count < result) {
				result = count;
			}
		}
	}

	cout << result;

	//이중배열 해제하기
	for (int i = 0; i < N; i++) {
		delete[]board[i];
	}
	delete[]board;

	return 0;
}