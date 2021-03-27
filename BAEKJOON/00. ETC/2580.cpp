#include <iostream>
using namespace std;

struct coordinate {
public:
	int x, y;
};

int map[9][9];
coordinate is_zero[81];
int num_of_zero;	//ºó Ä­ÀÇ °³¼ö

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool identify(int row, int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[row][i] == num) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (map[i][col] == num) return false;
	}
	for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
		for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
			if (map[i][j] == num) return false;
		}
	}

	return true;
}

void sdoku(int index) {
	if (index == num_of_zero) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 0; i <= 9; i++) {
		if (!identify(is_zero[index].y, is_zero[index].x, i)) continue;
		map[is_zero[index].y][is_zero[index].x] = i;
		sdoku(index + 1);
		map[is_zero[index].y][is_zero[index].x] = 0;
	}
}

int main(void) {

	init();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (!map[i][j]) {
				is_zero[num_of_zero].x = j;
				is_zero[num_of_zero].y = i;
				num_of_zero++;
			}
		}
	}
	
	sdoku(0);

	return 0;
}