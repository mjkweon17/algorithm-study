#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

#define X second
#define Y first

int map[1000][1000];
int visited[1000][1000][2];
int shortest_distance;
int N, M;	//N은 높이(y의 길이), M은 폭(x의 길이)

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void BFS() {

	queue<tuple<int, int, int>> Q;
	Q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;	//y, x, 벽
	int temp;

	while (!Q.empty()) {

		tuple<int, int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = get<0>(cur) + dy[i];
			int nx = get<1>(cur) + dx[i];
			int wall = get<2>(cur);
			if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;	//범위 초과

			if (wall) {	//이미 벽을 부셨으면
				if (map[ny][nx]) continue;	//이미 벽을 부셨기 때문에 또 벽을 만나면 못부숨
				temp = visited[get<0>(cur)][get<1>(cur)][wall] + 1;	//map[nx][ny]까지의 거리
				if (!visited[ny][nx][wall]) {	//그 길까지 벽을 부수면서 온 적이 없으면
					visited[ny][nx][wall] = temp;
					Q.push({ ny, nx, 1 });
				}
				else {	//그 길까지 벽을 부수면서 온 적이 한 번이라도 있으면
					if (visited[ny][nx][1] > temp) {	//이번에 부수면서 온 길이 더 작을 때
						visited[ny][nx][1] = temp;
						Q.push({ ny, nx, 1 });
					}
				}
			}
			else {	//한 번도 벽을 부수지 않았으면
				if (map[ny][nx]) {	//이번에 온 곳이 벽이면
					temp = visited[get<0>(cur)][get<1>(cur)][0] + 1;	//그 길까지의 거리
					if (!visited[ny][nx][1]) {	//그 길까지 벽을 부수면서 온 적이 없으면
						visited[ny][nx][1] = temp;
						Q.push({ ny, nx, 1 });
					}
					else {	//그 길까지 벽을 부수면서 온 적이 한 번이라도 있으면
						if (visited[ny][nx][1] > temp) {	//이번에 부수면서 온 길이 더 작을 때
							visited[ny][nx][1] = temp;
							Q.push({ ny, nx, 1 });
						}
					}
				}
				else {	//이번에 온 곳이 길이면
					if (visited[ny][nx][0]) continue;	//한 번이라도 왔다는 뜻
					visited[ny][nx][0] = visited[get<0>(cur)][get<1>(cur)][0] + 1;
					Q.push({ ny, nx, 0 });
				}
			}
		}
	}

	if (!visited[N - 1][M - 1][0]) {
		if (!visited[N - 1][M - 1][1]) {
			shortest_distance = -1;
		}
		else {
			shortest_distance = visited[N - 1][M - 1][1];
		}
	}
	else if (!visited[N - 1][M - 1][1]) {
		shortest_distance = visited[N - 1][M - 1][0];
	}
	else {
		if (visited[N - 1][M - 1][0] < visited[N - 1][M - 1][1]) {
			shortest_distance = visited[N - 1][M - 1][0];
		}
		else {
			shortest_distance = visited[N - 1][M - 1][1];
		}
	}
}

int main(void) {

	init();

	cin >> N >> M;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	BFS();

	cout << shortest_distance;

	return 0;
}