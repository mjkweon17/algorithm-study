#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

vector<vector<pair<int, int>>> tree;
int longest;
int long_index;
bool visited[1000001];

void dfs(int node, int cur_len) {
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		if (visited[tree[node][i].first]) continue;
		cur_len += tree[node][i].second;
		if (cur_len > longest) {
			longest = cur_len;
			long_index = tree[node][i].first;
		}
		dfs(tree[node][i].first, cur_len);
		cur_len -= tree[node][i].second;
	}
}

int main(void) {

	init();

	//정점의 개수 V를 입력받는다
	int V;
	cin >> V;
	tree.resize(V + 1);

	//트리 만들기: V줄 동안 i번째 정점과 연결된 (정점, 길이)를 입력받는다. 
	for (int i = 0; i < V; i++) {
		int index = 1;
		int vertex;
		int num_first;
		int num_second;
		while (true) {
			if (index == 1) {
				cin >> vertex;
				index++;
			}
			else if (index % 2) {
				cin >> num_second;
				tree[vertex].push_back(make_pair(num_first, num_second));
				index++;
			}
			else {
				cin >> num_first;
				index++;
				if (num_first == -1) {
					break;
				}
			}
		}
	}
	
	dfs(1, 0);
	for (int i = 0; i < V + 1; i++) {
		visited[i] = false;
	}
	dfs(long_index, 0);
	cout << longest;

	return 0;
}