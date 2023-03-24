#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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

	int M, N, K;	//가로가 N, 세로가 M
	cin >> M >> N >> K;

	vector<vector<int>> paper(N, vector<int>(M, 0));
	vector<vector<int>> vis(N, vector<int>(M, 0));

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				paper[j][k] = 1;
			}
		}
	}

	queue<pair<int, int>>Q;
	
	vector<int> territory;
	int area = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!paper[i][j] && !vis[i][j]) {
				area = 1;
				Q.push({ i, j });
				vis[i][j] = 1;

				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (paper[nx][ny] || vis[nx][ny]) continue;
						Q.push({ nx, ny });
						area++;
						vis[nx][ny] = 1;
					}
				}

				territory.push_back(area);
			}
		}
	}

	sort(territory.begin(), territory.end());

	cout << territory.size() << '\n';
	for (int i = 0; i < territory.size(); i++) {
		cout << territory[i] << ' ';
	}

	return 0;
}