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

	int N, M;	//N: ���� ����, M: ���� ����
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

	dist[0][0] = 1;	//���� ��ǥ���� ���� ��ǥ������ �Ÿ��� 1

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	//�� ��ǥ�� ������ �Ѿ ��
			if (!maze[nx][ny] || dist[nx][ny]) continue;	//�� ��ǥ�� ���� ���ų� �̹� ������ ���� ��
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;	//�� ��ǥ������ �Ÿ� ������Ʈ
			Q.push({ nx, ny });
		}
	}

	cout << dist[N - 1][M - 1];

	return 0;
}

//���� dist �迭�� -1�� �ʱ�ȭ�ϸ� �湮���θ� Ȯ���� �� �ִ�.