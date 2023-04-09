#include <iostream>
#include <vector>
#include <string>
using namespace std;

int biggest = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int sx[4] = { 0, 0, 1, 0 };	//for문의 i 시작 index
int sy[4] = { 0, 0, 0, 1 };	//for문의 j 시작 index
int ex[4] = {};	//for문의 종료 index
int ey[4] = {};
string cur[4] = { "down", "right", "up", "left" };	//테스트용
int test_move[5] = { 1, 0, 2, 3, 1 };	//테스트용

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

void copy_board(const vector<vector<int>>& original, vector<vector<int>>& copy) {
	int N = original.size();
	copy.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = original[i][j];
		}
	}
}

void print_board(const vector<vector<int>>& board) {
	int N = board.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void move(vector<vector<int>>& board, int moved) {
	if (moved > 5) return;
	int N = board.size();

	vector<vector<int>> cb;	//copied board
	for (int dir = 0; dir < 4; dir++) {
		//if (test_move[moved - 1] != dir) continue;

		copy_board(board, cb);	//보드 복사해주기

		//cout << endl << moved << ". " << cur[dir] << endl;	//테스트

		//한쪽으로 몰아주기
		for (int rep = 0; rep < N; rep++) {
			for (int i = sx[dir]; i < ex[dir]; i++) {
				for (int j = sy[dir]; j < ey[dir]; j++) {
					if (cb[i + dx[dir]][j + dy[dir]] == 0) {		
						cb[i + dx[dir]][j + dy[dir]] = cb[i][j];
						cb[i][j] = 0;
					}
				}
			}
		}

		//이웃한 같은 수들 합쳐주기
		for (int rep = 0; rep < N; rep++) {
			for (int i = sx[dir]; i < ex[dir]; i++) {
				for (int j = sy[dir]; j < ey[dir]; j++) {
					if (cb[i][j] == cb[i + dx[dir]][j + dy[dir]]) {
						cb[i][j] += cb[i + dx[dir]][j + dy[dir]];
						cb[i + dx[dir]][j + dy[dir]] = 0;
					}
				}
			}
		}

		//한쪽으로 몰아주기
		for (int rep = 0; rep < N; rep++) {
			for (int i = sx[dir]; i < ex[dir]; i++) {
				for (int j = sy[dir]; j < ey[dir]; j++) {
					if (cb[i + dx[dir]][j + dy[dir]] == 0) {
						if (dir == 0 || dir == 1) {
							cb[i + dx[dir]][j + dy[dir]] = cb[i][j];
							cb[i][j] = 0;
						}
						else {
							cb[i][j] = cb[i + dx[dir]][j + dy[dir]];
							cb[i + dx[dir]][j + dy[dir]] = 0;
						}
					}
				}
			}
		}

		//print_board(cb);


		//완성된 보드를 처음부터 끝까지 봐서 biggest 보다 큰 수가 있을 경우 biggest update
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (cb[row][col] > biggest) {
					biggest = cb[row][col];
					//cout << "new biggest!!!!!!!!" << biggest << endl;
				}
			}
		}

		move(cb, moved + 1);
	}
}

int main(void) {

	init();

	int N;
	cin >> N;
	ex[0] = N - 1; ex[1] = ex[2] = ex[3] = N;
	ey[1] = N - 1; ey[0] = ey[2] = ey[3] = N;

	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	move(board, 1);

	cout << biggest;

	return 0;
}