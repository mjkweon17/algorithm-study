#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<string, int> p1, pair<string, int> p2) {
	
	if (p1.second == p2.second) {
		for (int i = 0; i < p1.second; i++) {
			if (p1.first[i] == p2.first[i]) {
				continue;
			}
			return p1.first[i] < p2.first[i];
		}
	}

	return p1.second < p2.second;

}

int main(void) {

	int N;
	cin >> N;

	vector<pair<string, int>> V;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		V.push_back(make_pair(str, str.length()));
	}

	sort(V.begin(), V.end(), compare);

	cout << V[0].first << '\n';
	for (int i = 1; i < N; i++) {
		if (V[i].first == V[i - 1].first) {
			continue;
		}
		cout << V[i].first << '\n';
	}

	return 0;
}
