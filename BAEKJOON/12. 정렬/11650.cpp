#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.X == p2.X) {
		return p1.Y < p2.Y;
	}
	return p1.X < p2.X;
}

int main(void) {

	init();

	int N;
	cin >> N;

	vector<pair<int, int>> coord;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

	sort(coord.begin(), coord.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << coord[i].X << ' ' << coord[i].Y << '\n';
	}

	return 0;
}