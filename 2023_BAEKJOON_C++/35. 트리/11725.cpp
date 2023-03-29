#include <iostream>
#include <vector>
using namespace std;


void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void find_tree_parent(vector<vector<int>>& tree, int cur, int parent) {

	tree[cur][0] = parent;

	for (int i = 1; i < tree[cur].size(); i++) {
		if (tree[cur][i] != tree[cur][0]) {
			find_tree_parent(tree, tree[cur][i], cur);
		}
	}
}

int main(void) {

	init();

	int N;
	cin >> N;

	//tree[i][0]은 i번째 노드의 부모 노드.
	vector<vector<int>> tree(N + 1, vector<int>(1, 0));

	int ver1, ver2;
	for (int i = 0; i < N - 1; i++) {
		//N - 1만큼 한 줄에 두 정점 ver1, ver2를 입력받음
		cin >> ver1 >> ver2;
		tree[ver1].push_back(ver2);
		tree[ver2].push_back(ver1);
	}

	find_tree_parent(tree, 1, 0);
	
	//arr[2][0]부터 arr[N][0]까지의 값을 출력해줌
	for (int i = 2; i <= N; i++) {
		cout << tree[i][0] << "\n";
	}

	return 0;
}