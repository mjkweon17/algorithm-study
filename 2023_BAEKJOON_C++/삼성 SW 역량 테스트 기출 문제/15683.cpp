#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//�簢������ �ּ� ũ��
int blank_count = 100;

void copy_office(vector<vector<int>>& ori_office, vector<vector<int>>& copied_office) {
	for (int i = 0; i < ori_office.size(); i++) {
		for (int j = 0; j < ori_office[0].size(); j++) {
			copied_office[i][j] = ori_office[i][j];
		}
	}
}

//�簢���� ���� ��
void del_blank_top(vector<vector<int>>& copied_office, int row, int col) {
	for (int i = row; i >= 0; i--) {	
		if (copied_office[i][col] == 6) break;
		if (copied_office[i][col] == 0) 
			copied_office[i][col] = 7;
	}
}

//�簢���� ���� ��
void del_blank_bot(vector<vector<int>>& copied_office, int row, int col) {
	for (int i = row; i < copied_office.size(); i++) {	//�簢���� ���� ��
		if (copied_office[i][col] == 6) break;
		if (copied_office[i][col] == 0)
			copied_office[i][col] = 7;
	}
}

//�簢���� ���� ��
void del_blank_left(vector<vector<int>>& copied_office, int row, int col) {
	for (int i = col; i >= 0; i--) {
		if (copied_office[row][i] == 6) break;
		if (copied_office[row][i] == 0)
			copied_office[row][i] = 7;
	}
}

//�簢���� ���� ��
void del_blank_right(vector<vector<int>>& copied_office, int row, int col) {
	for (int i = col; i < copied_office[0].size(); i++) {	//�簢���� ���� ��
		if (copied_office[row][i] == 6) break;
		if (copied_office[row][i] == 0)
			copied_office[row][i] = 7;
	}
}

//�簢������ ũ�� ���ϱ�
void count_blank(vector<vector<int>>office, vector<pair<int, int>>CCTV, int checked) {
	
	int N = office.size();
	int M = office[0].size();

	if (checked == CCTV.size()) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0) count++;
			}
		}

		/*
		cout << "count " << count << "  blank_count" << blank_count << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << office[i][j] << " ";
			}
			cout << endl;
		}
		*/

		if (count < blank_count) blank_count = count;

		return;
	}
	
	vector<vector<int>> copied_office(N, vector<int>(M));
	int row = CCTV[checked].first;
	int col = CCTV[checked].second;
	switch (office[row][col]) {
	case 1:
		//��
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//��
		copy_office(office, copied_office);
		del_blank_bot(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//��
		copy_office(office, copied_office);
		del_blank_left(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//��
		copy_office(office, copied_office);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		break;
	case 2:
		//����
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_bot(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//�¿�
		copy_office(office, copied_office);
		del_blank_left(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		break;
	case 3:
		//���
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//����
		copy_office(office, copied_office);
		del_blank_bot(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//����
		copy_office(office, copied_office);
		del_blank_bot(copied_office, row, col);
		del_blank_left(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//�»�
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_left(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		break;
	case 4:
		//�»��
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_left(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//�����
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_bot(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//������
		copy_office(office, copied_office);
		del_blank_bot(copied_office, row, col);
		del_blank_left(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		//���»�
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_bot(copied_office, row, col);
		del_blank_left(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);

		break;
	case 5:
		copy_office(office, copied_office);
		del_blank_top(copied_office, row, col);
		del_blank_bot(copied_office, row, col);
		del_blank_left(copied_office, row, col);
		del_blank_right(copied_office, row, col);
		count_blank(copied_office, CCTV, checked + 1);
		break;
	default:
		break;
	}

	return;
}

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> office(N, vector<int>(M, 0));
	//CCTV�� ��ġ�� ������ �迭
	vector<pair<int, int>> CCTV;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5) {
				CCTV.push_back(make_pair(i, j));
			}
		}
	}

	count_blank(office, CCTV, 0);

	cout << blank_count;

	return 0;
}