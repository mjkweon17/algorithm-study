#include <iostream>
#include <vector>
#include <utility>
#include <queue>
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

	int T;	//테스트 케이스
	cin >> T;

	for (int t = 0; t < T; t++) {	//테스트 케이스 만큼 돌리기

		int worm = 0;

		int M, N, K;
		cin >> M >> N >> K;
		vector<vector<int>> farm(M, vector<int>(N, 0));
		vector<vector<int>> vis(M, vector<int>(N, 0));

		queue<pair<int, int>>Q;

		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			farm[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (farm[i][j] && !vis[i][j]) {
					Q.push({ i, j });
					vis[i][j] = 1;
					worm++;
					
					while (!Q.empty()) {
						pair<int, int> cur = Q.front();
						Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
							if (!farm[nx][ny] || vis[nx][ny]) continue;
							Q.push({ nx, ny });
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}

		cout << worm << '\n';
	}

	return 0;
}