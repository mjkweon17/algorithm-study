#include <iostream>
using namespace std;

int board[15][15];
int vis[15][15];
int cnt = 0;
int n;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void fill(int y, int x, int num) {
	for (int i = 0; x + i < n && y + i < n; i++) {	//우하 방향
		if (num) {
			board[y + i][x + i] = num;
			vis[y + i][x + i]++;
		}
		else {
			if (vis[y + i][x + i] == 1) {
				board[y + i][x + i] = num;
			}
			vis[y + i][x + i]--;
		}
	}

	for (int i = 0; x - i >= 0 && y + i < n; i++) {	//좌하 방향
		if (num) {
			board[y + i][x - i] = num;
			vis[y + i][x - i]++;
		}
		else {
			if (vis[y + i][x - i] == 1) {
				board[y + i][x - i] = num;
			}
			vis[y + i][x - i]--;
		}
	}

	for (int i = 0; y + i < n; i++) {	//하 방향
		if (num) {
			board[y + i][x] = num;
			vis[y + i][x]++;
		}
		else {
			if (vis[y + i][x] == 1) {
				board[y + i][x] = num;
			}
			vis[y + i][x]--;
		}
	}
}

void func(int k) {
	if (k == n) {	//base condition
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (board[k][i]) continue;

		fill(k, i, 1);
		func(k + 1);
		fill(k, i, 0);
	}
} 

int main(void) {

	init();

	cin >> n;

	func(0);

	cout << cnt;

	return 0;
}