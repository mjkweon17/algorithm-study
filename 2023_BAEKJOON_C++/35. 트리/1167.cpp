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

	//������ ���� V�� �Է¹޴´�
	int V;
	cin >> V;
	tree.resize(V + 1);

	//Ʈ�� �����: V�� ���� i��° ������ ����� (����, ����)�� �Է¹޴´�. 
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