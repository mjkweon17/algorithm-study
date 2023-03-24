#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second

int paper[501][501];  //도화지
int vis[501][501];    //방문 여부
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;  // n: 세로 크기, m: 가로 크기

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int count_picture = 0;  //그림의 개수
    int biggest_size = 0;   //가장 넓은 그림의 넓이

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (!paper[i][j] || vis[i][j]) continue;

            int size = 0;
            count_picture++;    //그림의 개수 증가

            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({ i,j });

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                size++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || !paper[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx, ny });
                }
            }

            if (size > biggest_size) {
                biggest_size = size;
            }
        }
    }

    cout << count_picture << '\n';
    cout << biggest_size;

    return 0;
}