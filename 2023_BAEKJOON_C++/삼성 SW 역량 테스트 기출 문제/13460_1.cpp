//������ �׽�Ʈ ���̽��� �� ����ϰ� �˻��ؼ� ã�� �ݷʵ� �� ����ϴµ� ������ �� Ǯ��
//���� ������ �Ķ� ������ '����'�� �������� �ʾƼ� �׷� �� ����
//���� Ǭ ����� �Ķ� ������ ���� �����̰� �Ķ� ������ ������ ��

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

bool success;
int check = 20;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void copy_board(vector<vector<char>> original, vector<vector<char>>& copied) {
	for (int i = 0; i < original.size(); i++) {
		for (int j = 0; j < original[0].size(); j++) {
			copied[i][j] = original[i][j];
		}
	}
}

void lean(vector<vector<char>>board, vector<vector<int>> vis, int count) {

	if (success) {
		if (count >= check) return;
	}
	if (count >= 10) return;


	//cout << endl << endl << "�׽�Ʈ ���� count: " << count << endl << endl;

	int N = board.size();
	int M = board[0].size();
	int red_row, red_col;	//���� ������ ��ǥ
	int blue_row, blue_col;	//�Ķ� ������ ��ǥ
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (board[i][j] == 'B') {
				blue_row = i;
				blue_col = j;
			}
			if (board[i][j] == 'R') {
				red_row = i;
				red_col = j;
			}
		}
	}

	//���� ������ ���� ��ġ�� �� ���� �ִ��� Ȯ��. ���� �ִٸ� return
	bool visited = false;
	for (int i = 0; i < vis.size(); i++) {
		if (vis[i][0] == red_row && vis[i][1] == red_col) {
			visited = true;
			if (vis[i][2] >= check) {
				return;
			}
			else {
				vis[i][2] = check;
			}
		}
	}
	if (!visited) {
		vis.push_back({ red_row, red_col, count });
	}

	for (int i = 0; i < 4; i++) {

		vector<vector<char>> cb(N, vector<char>(M)); //copied_board cb �����
		copy_board(board, cb);

		bool fail = false;	//���� �Ķ� ������ ���ۿ� �����ų�, ���� ������ �������� fail
		int j = 0;	//�̵��� �Ÿ�

		//cout << "�׽�Ʈ �Ķ� ���� ���� count: " << count << " i" << i << endl;

		//�Ķ� ���� �̵�
		j = 0;
		int br, bc; //���� �Ķ� ������ ��ǥ
		bool overlap = false;	//�Ķ� ������ ���� ������ ���� ��ġ�� true
		while (true) {
			br = blue_row + j * dx[i]; bc = blue_col + j * dy[i];
			//cout << "�׽�Ʈ �Ķ� ���� ��ǥ at j" << j << ": " << br << " " << bc << endl;

			//�Ķ� ���� �����̱�
			if (cb[br][bc] == '#') break;
			else if (cb[br][bc] == 'B') {}
			else if (cb[br][bc] == 'R') {
				overlap = true;
			}
			else if (cb[br][bc] == 'O') {
				fail = true;
				break;
			}
			else if (cb[br][bc] == '.') {
				if (!overlap) {
					cb[br - dx[i]][bc - dy[i]] = '.';
					cb[br][bc] = 'B';
				}
			}
			j++;
		}

		//cout << "�׽�Ʈ �Ķ� ���� ��" << endl;

		if (fail) continue;

		//���� ���� �̵�
		//cout << "�׽�Ʈ ���� ���� ���� count: " << count << " i" << i << endl;

		j = 0;
		int rr, rc; //���� �Ķ� ������ ��ǥ
		while (true) {
			rr = red_row + j * dx[i]; rc = red_col + j * dy[i];
			//cout << "�׽�Ʈ ���� ���� ��ǥ at j" << j << ": " << rr << " " << rc << endl;
			if (cb[rr][rc] == '#') break;
			else if (cb[rr][rc] == 'B') {
				break;
			}
			else if (cb[rr][rc] == 'R') {}
			else if (cb[rr][rc] == 'O') {
				success = true;
				if (count < check) check = count;
				return;
			}
			else if (cb[rr][rc] == '.') {
				cb[rr - dx[i]][rc - dy[i]] = '.';
				cb[rr][rc] = 'R';
			}
			j++;
		}

		//cout << "�׽�Ʈ ���� ���� ��" << endl;

		if (fail) continue;

		//cout << "�׽�Ʈ �������� count: " << count << endl;

		lean(cb, vis, count + 1);
	}

	return;
	
}

int main(void) {

	init();

	int N, M;
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<int>> vis;	//���� ������ ��ġ�� ������ ����	//row, col, �ּ� count
	lean(board, vis, 0);

	if (check > 10 || !success) {
		cout << -1;
	}
	else {
		cout << check + 1;
	}

	return 0;
}