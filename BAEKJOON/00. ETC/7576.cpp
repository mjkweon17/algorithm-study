#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };	//상하좌우 구할 때 사용할 배열

int main(void) {

	int N, M;
	cin >> M >> N;

	int day = 0;	//토마토가 전부 익기까지 걸리는 시간

	bool no_ripen = false;	//상자에 0이 있는지 판별. true이 결우 익지 않은 토마토가 있다.
	int temp;
	vector<vector<int>>box(N, vector<int>(M, 0));	//N*M 상자 만들기
	for (int i = 0; i < N; i++) {	//상자에 토마토 정보 입력
		for (int j = 0; j < M; j++) {
			cin >> temp;
			box[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++) {	//상자에 0이 있는지 판별.
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {	//만약 0이 있으면 익지 않은 것이 있다.
				no_ripen = true;
				break;
			}
		}
	}

	if (!no_ripen) {	//만약 익지 않은 토마토가 없으면 day 출력하고 프로그램 종료
		cout << day;
		return 0;
	}

	int today_count = 0; //오늘 큐에 들어온 토마토의 수 count

	queue<pair<int, int>>Q;
	for (int i = 0; i < N; i++) {	//현재 익은 토마토 큐에 담기
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1) {
				Q.push({ i, j });
				today_count++;	//1일차에 익었던 토마토 큐에 담기
			}
		}
	}

	//day 관련 연산은 다시 손봐야함

	while (!Q.empty()) {
		int yesterday_count = today_count;	//어제 큐에 담긴 토마토의 개수
		today_count = 0;
		for (int i = 0; i < yesterday_count; i++) {	//전날 큐에 새로 들어온 토마토 수만큼 반복
			pair<int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	//범위 넘어갈 때
				if (box[nx][ny]) continue;	//익지 않은 토마토가 아니면
				box[nx][ny] = 1;	//토마토 익히기
				Q.push({ nx, ny });
				today_count++;
			}
		}

		if (today_count) {
			day++;
		}

	}

	for (int i = 0; i < N; i++) {	//상자에 0이 있는지 판별.
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {	//만약 0이 있으면 익지 않은 것이 있다.
				day = -1;	//익지 않은 토마토가 있다!
				break;
			}
		}
	}

	cout << day;

	return 0;
}