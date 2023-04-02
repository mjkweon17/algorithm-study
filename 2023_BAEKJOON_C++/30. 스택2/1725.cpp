#include <iostream>
#include <stack>
#include <utility>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int hist[100001];

int main(void) {

	int N;	//히스토그램의 가로 칸 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hist[i];
	}

	stack<pair<int, int>> S;	//<높이, 시작 index>
	int largest = 0;
	for (int i = 0; i < N; i++) {
		int start = i;
		while (!S.empty() && S.top().first > hist[i]) {
			pair<int, int>p = S.top();
			S.pop();
			start = p.second;
			int area = p.first * (i - p.second);
			if (area > largest) largest = area;
		}
		S.push(make_pair(hist[i], start));
	}

	while (!S.empty()) {
		pair<int, int>p = S.top();
		S.pop();
		int area = p.first * (N - p.second);
		if (area > largest) largest = area;
	}
	
	cout << largest;

	return 0;
}