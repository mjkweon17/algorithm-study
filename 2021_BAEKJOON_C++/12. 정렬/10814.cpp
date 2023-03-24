#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<int, string> p1, pair<int, string> p2) {
	return p1.first < p2.first;
}

int main(void) {

	init();

	int N;
	cin >> N;

	vector<pair<int, string>> V;

	int age;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		V.push_back(make_pair(age, name));
	}

	stable_sort(V.begin(), V.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << V[i].first << ' ' << V[i].second << '\n';
	}

	return 0;
}