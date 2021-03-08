#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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

	vector<int>house;

	int N;
	cin >> N;

	vector<vector<int>>map(N, vector<int>(N));
	vector<vector<int>>vis(N, vector<int>(N, 0));
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	queue<pair<int, int>> Q;

	int num_house;	//집의 개수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !vis[i][j]) {
				num_house = 0;
				Q.push({ i,j });
				vis[i][j] = 1;
				num_house++;
				while (!Q.empty()) {
					pair<int, int>cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (!map[nx][ny] || vis[nx][ny]) continue;
						Q.push({ nx, ny });
						num_house++;
						vis[nx][ny] = 1;
					}
				}
				house.push_back(num_house);
			}
		}
	}

	sort(house.begin(), house.end());
	cout << house.size() << '\n';
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << '\n';
	}

	return 0;
}