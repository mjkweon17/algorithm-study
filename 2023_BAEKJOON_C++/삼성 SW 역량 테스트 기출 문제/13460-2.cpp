#include <iostream>
#include <vector>
using namespace std;

bool success;
int check = 20;

void copy_board(const vector<vector<char>>& original, vector<vector<char>>& copy) {
	int N = original.size();
	int M = original[0].size();
	copy.resize(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = original[i][j];
		}
	}
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void lean(vector<vector<char>>& board, vector<vector<int>>vis, int count) {

	if (count >= 10) return;
	if (check <= count) return;
	
	int N, M;	//board의 크기
	N = board.size(); M = board[0].size();
	int rr, rc, br, bc;	//현재 board에서 빨간 구슬, 파란 구슬의 위치를 찾아 저장
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (board[i][j] == 'R') {
				rr = i;	rc = j;
			}
			if (board[i][j] == 'B') {
				br = i;	bc = j;
			}
		}
	}

	bool visited = false;
	//빨간 구슬과 파란 구슬이 현재 위치로 온적이 있다
	for (int i = 0; i < vis.size(); i++) {
		if (vis[i][0] == rr && vis[i][1] == rc && vis[i][2] == br && vis[i][3] == bc) {
			visited = true; break;
		}
	}
	if (visited) {
		return;
	}
	else {
		vis.push_back({ rr, rc, br, bc });
	}

	vector<vector<char>> cb;	//copied board

	//빨간 구슬과 파란 구슬 4방향으로 움직이기
	for (int i = 0; i < 4; i++) {
		//cout << endl << endl << "check" << count << ", i: " << i << endl;

		copy_board(board, cb);
		bool rf, bf;	//red_finish, blue_finish	공의 움직임이 끝났다는 뜻
		int rm, bm;	//red_move, blue_move	빨간 공과 파란 공이 움직인 횟수
		int crr, crc, cbr, cbc;	//현재 공들의 위치
		rf = bf = false;
		rm = bm = 1;
		bool temp_success = false;
		while (!rf || !bf) {
			//print_board(cb);
			//cout << endl;
			if (!bf) {
				cbr = br + bm * dx[i];
				cbc = bc + bm * dy[i];
				if (cb[cbr][cbc] == '#') {
					bf = true;
				}
				else if (cb[cbr][cbc] == 'O') {
					return;
				}
				else if (cb[cbr][cbc] == 'R') {
					if (cb[cbr + dx[i]][cbc + dy[i]] == '#') {
						bf = true;
					}
					bm--;
				}
				else if (cb[cbr][cbc] == '.') {
					cb[cbr - dx[i]][cbc - dy[i]] = '.';
					cb[cbr][cbc] = 'B';
				}
				bm++;
			}
			if (!rf) {
				crr = rr + rm * dx[i];
				crc = rc + rm * dy[i];

				if (cb[crr][crc] == '#') {
					rf = true;
				}
				else if (cb[crr][crc] == 'O') {
					cb[crr - dx[i]][crc - dy[i]] = '.';
					temp_success = true;
					rf = true;
				}
				else if (cb[crr][crc] == 'B') {
					if (cb[crr + dx[i]][crc + dy[i]] == '#') {
						rf = true;
					}
					rm--;
				}
				else if (cb[crr][crc] == '.') {
					cb[crr - dx[i]][crc - dy[i]] = '.';
					cb[crr][crc] = 'R';
				}
				rm++;
			}
		}

		if (temp_success) {
			success = true;
			check = count;
			return;
		}
		lean(cb, vis, count + 1);
	}
}

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	vector<vector<int>> vis;
	lean(board, vis, 0);


	if (!success || check >= 10) {
		cout << -1;
	}
	else {
		cout << check + 1;
	}

	return 0;
}