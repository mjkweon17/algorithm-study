#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int time = 0;	//탈출시간
	
	int j_moved_yesterday;
	int j_moved_today = 1;
	int f_moved_yesterday;
	int f_moved_today = 0;

	bool finished = false;
	bool burned = false;

	int R, C;
	cin >> R >> C;

	vector<vector<char>> maze(R, vector<char>(C));

	queue<pair<int, int>>J;
	queue<pair<int, int>>F;

	char temp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			maze[i][j] = temp;
			if (temp == 'J') {
				J.push({ i,j });
			}
			if (temp == 'F') {
				F.push({ i,j });
				f_moved_today++;
			}
		}
	}

	while (true) {
		//지훈이 움직이기
		j_moved_yesterday = j_moved_today;
		j_moved_today = 0;
		for (int i = 0; i < j_moved_yesterday; i++) {
			pair<int, int> cur = J.front();
			J.pop();
			if (maze[cur.X][cur.Y] != 'J') {
				continue;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx >= R || ny >= C || nx < 0 || ny < 0) {
					finished = true;
					break;
				}
				if (maze[nx][ny] != '.') continue;
				maze[nx][ny] = 'J';
				J.push({ nx, ny });
				j_moved_today++;
			}
			if (finished) {
				break;
			}
		}

		time++;

		if (finished) {
			break;
		}

		if (!j_moved_today) {
			burned = true;
			break;
		}

		//불 움직이기

		f_moved_yesterday = f_moved_today;
		f_moved_today = 0;
		for (int i = 0; i < f_moved_yesterday; i++) {
			pair<int, int> cur = F.front();
			F.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx >= R || ny >= C || nx < 0 || ny < 0) continue;
				if (maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;
				maze[nx][ny] = 'F';
				F.push({ nx, ny });
				f_moved_today++;
			}
		}

		bool have_J = false;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (maze[i][j] == 'J') {
					have_J = true;
				}
			}
		}

		if (!have_J) {
			burned = true;
		}

		if (burned) {
			break;
		}
	}

	if (burned) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << time;
	}

	return 0;
}