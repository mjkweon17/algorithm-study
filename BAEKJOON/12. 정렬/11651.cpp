#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.Y == p2.Y) {
		return p1.X < p2.X;
	}
	return p1.Y < p2.Y;
}

int main(void) {

	int N;
	cin >> N;

	vector<pair<int, int>> V;

	int x, y;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		V.push_back(make_pair(x, y));
	}

	sort(V.begin(), V.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << V[i].X << ' ' << V[i].Y << '\n';
	}

	return 0;
}