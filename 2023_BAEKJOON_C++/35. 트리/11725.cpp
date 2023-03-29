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

	//tree[i][0]�� i��° ����� �θ� ���.
	vector<vector<int>> tree(N + 1, vector<int>(1, 0));

	int ver1, ver2;
	for (int i = 0; i < N - 1; i++) {
		//N - 1��ŭ �� �ٿ� �� ���� ver1, ver2�� �Է¹���
		cin >> ver1 >> ver2;
		tree[ver1].push_back(ver2);
		tree[ver2].push_back(ver1);
	}

	find_tree_parent(tree, 1, 0);
	
	//arr[2][0]���� arr[N][0]������ ���� �������
	for (int i = 2; i <= N; i++) {
		cout << tree[i][0] << "\n";
	}

	return 0;
}