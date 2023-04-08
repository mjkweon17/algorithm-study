//백준의 테스트 케이스는 다 통과하고 검색해서 찾은 반례도 다 통과하는데 문제가 안 풀림
//빨간 구슬과 파란 구슬을 '동시'에 움직이지 않아서 그런 거 같음
//내가 푼 방식은 파란 구슬을 먼저 움직이고 파란 구슬을 움직인 것

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

bool success;
int check = 20;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void copy_board(vector<vector<char>> original, vector<vector<char>>& copied) {
	for (int i = 0; i < original.size(); i++) {
		for (int j = 0; j < original[0].size(); j++) {
			copied[i][j] = original[i][j];
		}
	}
}

void lean(vector<vector<char>>board, vector<vector<int>> vis, int count) {

	if (success) {
		if (count >= check) return;
	}
	if (count >= 10) return;


	//cout << endl << endl << "테스트 시작 count: " << count << endl << endl;

	int N = board.size();
	int M = board[0].size();
	int red_row, red_col;	//빨간 구슬의 좌표
	int blue_row, blue_col;	//파란 구슬의 좌표
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (board[i][j] == 'B') {
				blue_row = i;
				blue_col = j;
			}
			if (board[i][j] == 'R') {
				red_row = i;
				red_col = j;
			}
		}
	}

	//빨간 구슬이 현재 위치에 온 적이 있는지 확인. 만약 있다면 return
	bool visited = false;
	for (int i = 0; i < vis.size(); i++) {
		if (vis[i][0] == red_row && vis[i][1] == red_col) {
			visited = true;
			if (vis[i][2] >= check) {
				return;
			}
			else {
				vis[i][2] = check;
			}
		}
	}
	if (!visited) {
		vis.push_back({ red_row, red_col, count });
	}

	for (int i = 0; i < 4; i++) {

		vector<vector<char>> cb(N, vector<char>(M)); //copied_board cb 만들기
		copy_board(board, cb);

		bool fail = false;	//만약 파란 구슬이 구멍에 빠지거나, 빨간 구슬과 겹쳐지면 fail
		int j = 0;	//이동한 거리

		//cout << "테스트 파란 구슬 시작 count: " << count << " i" << i << endl;

		//파란 구슬 이동
		j = 0;
		int br, bc; //현재 파란 구슬의 좌표
		bool overlap = false;	//파란 구슬이 빨간 구슬에 의해 겹치면 true
		while (true) {
			br = blue_row + j * dx[i]; bc = blue_col + j * dy[i];
			//cout << "테스트 파란 구슬 좌표 at j" << j << ": " << br << " " << bc << endl;

			//파란 구슬 움직이기
			if (cb[br][bc] == '#') break;
			else if (cb[br][bc] == 'B') {}
			else if (cb[br][bc] == 'R') {
				overlap = true;
			}
			else if (cb[br][bc] == 'O') {
				fail = true;
				break;
			}
			else if (cb[br][bc] == '.') {
				if (!overlap) {
					cb[br - dx[i]][bc - dy[i]] = '.';
					cb[br][bc] = 'B';
				}
			}
			j++;
		}

		//cout << "테스트 파란 구슬 끝" << endl;

		if (fail) continue;

		//빨간 구슬 이동
		//cout << "테스트 빨간 구슬 시작 count: " << count << " i" << i << endl;

		j = 0;
		int rr, rc; //현재 파란 구슬의 좌표
		while (true) {
			rr = red_row + j * dx[i]; rc = red_col + j * dy[i];
			//cout << "테스트 빨간 구슬 좌표 at j" << j << ": " << rr << " " << rc << endl;
			if (cb[rr][rc] == '#') break;
			else if (cb[rr][rc] == 'B') {
				break;
			}
			else if (cb[rr][rc] == 'R') {}
			else if (cb[rr][rc] == 'O') {
				success = true;
				if (count < check) check = count;
				return;
			}
			else if (cb[rr][rc] == '.') {
				cb[rr - dx[i]][rc - dy[i]] = '.';
				cb[rr][rc] = 'R';
			}
			j++;
		}

		//cout << "테스트 빨간 구슬 끝" << endl;

		if (fail) continue;

		//cout << "테스트 다음으로 count: " << count << endl;

		lean(cb, vis, count + 1);
	}

	return;
	
}

int main(void) {

	init();

	int N, M;
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<int>> vis;	//빨간 구슬의 위치를 저장한 벡터	//row, col, 최소 count
	lean(board, vis, 0);

	if (check > 10 || !success) {
		cout << -1;
	}
	else {
		cout << check + 1;
	}

	return 0;
}