#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };	//�����¿� ���� �� ����� �迭

int main(void) {

	int N, M;
	cin >> M >> N;

	int day = 0;	//�丶�䰡 ���� �ͱ���� �ɸ��� �ð�

	bool no_ripen = false;	//���ڿ� 0�� �ִ��� �Ǻ�. true�� ��� ���� ���� �丶�䰡 �ִ�.
	int temp;
	vector<vector<int>>box(N, vector<int>(M, 0));	//N*M ���� �����
	for (int i = 0; i < N; i++) {	//���ڿ� �丶�� ���� �Է�
		for (int j = 0; j < M; j++) {
			cin >> temp;
			box[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++) {	//���ڿ� 0�� �ִ��� �Ǻ�.
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {	//���� 0�� ������ ���� ���� ���� �ִ�.
				no_ripen = true;
				break;
			}
		}
	}

	if (!no_ripen) {	//���� ���� ���� �丶�䰡 ������ day ����ϰ� ���α׷� ����
		cout << day;
		return 0;
	}

	int today_count = 0; //���� ť�� ���� �丶���� �� count

	queue<pair<int, int>>Q;
	for (int i = 0; i < N; i++) {	//���� ���� �丶�� ť�� ���
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1) {
				Q.push({ i, j });
				today_count++;	//1������ �;��� �丶�� ť�� ���
			}
		}
	}

	//day ���� ������ �ٽ� �պ�����

	while (!Q.empty()) {
		int yesterday_count = today_count;	//���� ť�� ��� �丶���� ����
		today_count = 0;
		for (int i = 0; i < yesterday_count; i++) {	//���� ť�� ���� ���� �丶�� ����ŭ �ݺ�
			pair<int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	//���� �Ѿ ��
				if (box[nx][ny]) continue;	//���� ���� �丶�䰡 �ƴϸ�
				box[nx][ny] = 1;	//�丶�� ������
				Q.push({ nx, ny });
				today_count++;
			}
		}

		if (today_count) {
			day++;
		}

	}

	for (int i = 0; i < N; i++) {	//���ڿ� 0�� �ִ��� �Ǻ�.
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {	//���� 0�� ������ ���� ���� ���� �ִ�.
				day = -1;	//���� ���� �丶�䰡 �ִ�!
				break;
			}
		}
	}

	cout << day;

	return 0;
}