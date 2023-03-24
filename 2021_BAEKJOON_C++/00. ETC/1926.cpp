#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second

int paper[501][501];  //��ȭ��
int vis[501][501];    //�湮 ����
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;  // n: ���� ũ��, m: ���� ũ��

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int count_picture = 0;  //�׸��� ����
    int biggest_size = 0;   //���� ���� �׸��� ����

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (!paper[i][j] || vis[i][j]) continue;

            int size = 0;
            count_picture++;    //�׸��� ���� ����

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