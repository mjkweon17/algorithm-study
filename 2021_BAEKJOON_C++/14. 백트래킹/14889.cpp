#include <iostream>
#include <cmath>
using namespace std;

int N;	//»ç¶÷ ¼ö
int arr[20][20];
int team_start[10];
int team_link[10];
int team_start_index;
int team_link_index;
int diff = 2000;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void func(int k) {
	if (k == N - 1) {	//base condition
		int team_start_score = 0;
		int team_link_score = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				team_start_score += arr[team_start[i]][team_start[j]];
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				team_link_score += arr[team_link[i]][team_link[j]];
			}
		}

		if (diff > abs(team_start_score - team_link_score)) {
			diff = abs(team_start_score - team_link_score);
		}
		
		return;
	}
	if (k == 0) {
		team_start[team_start_index] = 0;
		team_start_index++;
	}

	if (team_start_index != N / 2) {
		team_start[team_start_index] = k + 1;
		team_start_index++;
		cout << "start: " << k + 1 << endl;
		func(k + 1);
		team_start_index--;
	}

	if (team_link_index != N / 2) {
		team_link[team_link_index] = k + 1;
		team_link_index++;
		cout << "link: " << k + 1 << endl;
		func(k + 1);
		team_link_index--;
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	func(0);

	cout << diff;

	return 0;
}