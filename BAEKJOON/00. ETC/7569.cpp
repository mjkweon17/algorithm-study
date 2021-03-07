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

	//0. 앞으로 사용될 변수 생성하기

	int day = 0;	//익는데 걸리는 시간
	int today_count;	//오늘 익은 토마토의 개수
	int yesterday_count;	//어제 익은 토마토의 개수

	//1. 토마토 상자 만들기

	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> box(M, vector<vector<int>>(N, vector<int>(H)));

	//2. 토마토 상자에 토마토 심기

	int temp;	//토마토 상태 임시로 저장할 값
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> temp;
				box[k][j][i] = temp;
			}
		}
	}

	//3. 토마토 상자 확인하기

	bool have_none_ripen = false;	//하나라도 안익은 토마토가 있는지 확인
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
		//익지 않은 토마토가 없으면 0 출력 후 종료

	if (!have_none_ripen) {
		cout << day;
		return 0;
	}
		//익지 않은 토마토가 있으면 계속

	//4. 토마토 익히기
		
		//첫 날에 1인 토마토 인근의 토마토 전부 1로 만들고 큐에 집어 놓기

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
			//전 날 큐에 들어왔던 토마토 하나씩 pop
			pair<int, pair<int, int>> cur = Q.front();
			Q.pop();

			//pop했던 토마토 인근의 토마토 체크
			for (int dir = 0; dir < 6; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				int nz = cur.Z + dz[dir];

				//if 범위 넘어가면 continue;
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
				//if '익지않음' 상태 아니면 continue;
				if (box[nx][ny][nz] != 0) continue;
				//토마토 익히고 큐에 push
				box[nx][ny][nz] = 1;
				Q.push({ nx, {ny, nz} });

				today_count++;
			}

			//만약 0에서 1로 바뀐 토마토가 하나라도 있으면 day++
		}

		if (today_count) {
			day++;
		}
	}

	//5. 토마토 상자 확인하기
	have_none_ripen = false;	//모든 토마토가 익었다고 가정
		//익지 않은 토마토가 하나라도 있으면 day에 -1
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