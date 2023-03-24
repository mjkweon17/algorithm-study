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
int N, M;	//N�� ����(y�� ����), M�� ��(x�� ����)

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
	visited[0][0][0] = 1;	//y, x, ��
	int temp;

	while (!Q.empty()) {

		tuple<int, int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = get<0>(cur) + dy[i];
			int nx = get<1>(cur) + dx[i];
			int wall = get<2>(cur);
			if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;	//���� �ʰ�

			if (wall) {	//�̹� ���� �μ�����
				if (map[ny][nx]) continue;	//�̹� ���� �μ̱� ������ �� ���� ������ ���μ�
				temp = visited[get<0>(cur)][get<1>(cur)][wall] + 1;	//map[nx][ny]������ �Ÿ�
				if (!visited[ny][nx][wall]) {	//�� ����� ���� �μ��鼭 �� ���� ������
					visited[ny][nx][wall] = temp;
					Q.push({ ny, nx, 1 });
				}
				else {	//�� ����� ���� �μ��鼭 �� ���� �� ���̶� ������
					if (visited[ny][nx][1] > temp) {	//�̹��� �μ��鼭 �� ���� �� ���� ��
						visited[ny][nx][1] = temp;
						Q.push({ ny, nx, 1 });
					}
				}
			}
			else {	//�� ���� ���� �μ��� �ʾ�����
				if (map[ny][nx]) {	//�̹��� �� ���� ���̸�
					temp = visited[get<0>(cur)][get<1>(cur)][0] + 1;	//�� ������� �Ÿ�
					if (!visited[ny][nx][1]) {	//�� ����� ���� �μ��鼭 �� ���� ������
						visited[ny][nx][1] = temp;
						Q.push({ ny, nx, 1 });
					}
					else {	//�� ����� ���� �μ��鼭 �� ���� �� ���̶� ������
						if (visited[ny][nx][1] > temp) {	//�̹��� �μ��鼭 �� ���� �� ���� ��
							visited[ny][nx][1] = temp;
							Q.push({ ny, nx, 1 });
						}
					}
				}
				else {	//�̹��� �� ���� ���̸�
					if (visited[ny][nx][0]) continue;	//�� ���̶� �Դٴ� ��
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