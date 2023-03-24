#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second.first
#define Z second.second

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	//0. ������ ���� ���� �����ϱ�

	int day = 0;	//�ʹµ� �ɸ��� �ð�
	int today_count;	//���� ���� �丶���� ����
	int yesterday_count;	//���� ���� �丶���� ����

	//1. �丶�� ���� �����

	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> box(M, vector<vector<int>>(N, vector<int>(H)));

	//2. �丶�� ���ڿ� �丶�� �ɱ�

	int temp;	//�丶�� ���� �ӽ÷� ������ ��
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> temp;
				box[k][j][i] = temp;
			}
		}
	}

	//3. �丶�� ���� Ȯ���ϱ�

	bool have_none_ripen = false;	//�ϳ��� ������ �丶�䰡 �ִ��� Ȯ��
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[k][j][i] == 0) {
					have_none_ripen = true;
					break;
				}
			}
		}
	}
		//���� ���� �丶�䰡 ������ 0 ��� �� ����

	if (!have_none_ripen) {
		cout << day;
		return 0;
	}
		//���� ���� �丶�䰡 ������ ���

	//4. �丶�� ������
		
		//ù ���� 1�� �丶�� �α��� �丶�� ���� 1�� ����� ť�� ���� ����

	queue < pair<int, pair<int, int>>> Q;

	today_count = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[k][j][i] == 1) {
					Q.push({ k, {j, i} });
					today_count++;
				}
			}
		}
	}

	while (!Q.empty()) {
		yesterday_count = today_count;
		today_count = 0;

		for (int i = 0; i < yesterday_count; i++) {
			//�� �� ť�� ���Դ� �丶�� �ϳ��� pop
			pair<int, pair<int, int>> cur = Q.front();
			Q.pop();

			//pop�ߴ� �丶�� �α��� �丶�� üũ
			for (int dir = 0; dir < 6; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				int nz = cur.Z + dz[dir];

				//if ���� �Ѿ�� continue;
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
				//if '��������' ���� �ƴϸ� continue;
				if (box[nx][ny][nz] != 0) continue;
				//�丶�� ������ ť�� push
				box[nx][ny][nz] = 1;
				Q.push({ nx, {ny, nz} });

				today_count++;
			}

			//���� 0���� 1�� �ٲ� �丶�䰡 �ϳ��� ������ day++
		}

		if (today_count) {
			day++;
		}
	}

	//5. �丶�� ���� Ȯ���ϱ�
	have_none_ripen = false;	//��� �丶�䰡 �;��ٰ� ����
		//���� ���� �丶�䰡 �ϳ��� ������ day�� -1
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[k][j][i] == 0) {
					have_none_ripen = true;
					break;
				}
			}
		}
	}

	if (have_none_ripen) {
		day = -1;
	}
	
	cout << day;

	return 0;
}