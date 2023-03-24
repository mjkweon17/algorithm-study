#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int n, v;
	cin >> n >> v;

	int count = 0;

	vector<vector<int>>graph(n + 1, vector<int>(n + 1, 0));
	vector<int> vis(n + 1, 0);

	for (int i = 0; i < v; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		graph[temp1][temp2] = graph[temp2][temp1] = 1;
	}

	queue<int> Q;
	Q.push(1);
	vis[1] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int i = 1; i < n + 1; i++) {
			if (graph[cur][i] && !vis[i]) {
				Q.push(i);
				vis[i] = 1;
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
