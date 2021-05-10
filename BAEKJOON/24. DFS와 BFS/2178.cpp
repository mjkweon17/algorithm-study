#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void) {

	int N, M;	//N: 세로 길이, M: 가로 길이
	cin >> N >> M;

	vector<vector<int>>maze(N, vector<int>(M, 0));
	vector<vector<int>>dist(N, vector<int>(M, 0));

	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			maze[i][j] = temp - '0';
		}
	}

	dist[0][0] = 1;	//시작 좌표에서 시작 좌표까지의 거리는 1

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	//새 좌표가 범위를 넘어갈 때
			if (!maze[nx][ny] || dist[nx][ny]) continue;	//새 좌표에 길이 없거나 이미 지나온 길일 때
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;	//새 좌표까지의 거리 업데이트
			Q.push({ nx, ny });
		}
	}

	cout << dist[N - 1][M - 1];

	return 0;
}

//만약 dist 배열을 -1로 초기화하면 방문여부를 확인할 수 있다.