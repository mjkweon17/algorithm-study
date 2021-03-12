#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void init();
bool compare(pair<int, int> p1, pair<int, int> p2);
bool compare1(int a, int b);
void DFS(vector<pair<int, int>>& info, int N, int M, int V);
void BFS(vector<pair<int, int>>& info, int N, int M, int V);

int main(void) {

	init();

	int N, M, V;	//정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호
	cin >> N >> M >> V;

	vector<pair<int, int>> info;
	pair<int, int> temp;

	for (int i = 0; i < M; i++) {
		cin >> temp.first >> temp.second;
		info.push_back(temp);
	}
	
	DFS(info, N, M, V);

	cout << '\n';

	BFS(info, N, M, V);

	return 0;
}

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

bool compare1(int a, int b) {
	return a > b;
}

void DFS(vector<pair<int, int>>& info, int N, int M, int V) {

	vector<int>vis(N + 1, 0);

	stack<int> S;
	S.push(V);

	while (!S.empty()) {
		vector<int> temp;
		int cur = S.top();
		S.pop();
		if (!vis[cur]) {
			cout << cur << ' ';
			vis[cur] = 1;
		}

		for (int i = 0; i < M ; i++) {
			if (info[i].first == cur && !vis[info[i].second]) {
				temp.push_back(info[i].second);
			}
			else if (info[i].second == cur && !vis[info[i].first]) {
				temp.push_back(info[i].first);
			}
		}

		sort(temp.begin(), temp.end(), compare1);
		for (int i = 0; i < temp.size(); i++) {
			S.push(temp[i]);
		}
	}
}

void BFS(vector<pair<int, int>>& info, int N, int M, int V) {

	vector<int>vis(N + 1, 0);

	queue<int> Q;
	Q.push(V);
	vis[V] = 1;
	while (!Q.empty()) {
		vector<int> temp;
		int cur = Q.front();
		Q.pop();
		cout << cur << ' ';

		for (int i = 0; i < M; i++) {
			if (info[i].first == cur && !vis[info[i].second]) {
				temp.push_back(info[i].second);
				vis[info[i].second] = 1;
			}
			else if (info[i].second == cur && !vis[info[i].first]) {
				temp.push_back(info[i].first);
				vis[info[i].first] = 1;
			}
		}

		sort(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {
			Q.push(temp[i]);
		}
	}
}

//반례 모음집: https://www.acmicpc.net/board/view/24356