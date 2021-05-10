#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int N, K;	//N: ¼öºó, K: µ¿»ý
	cin >> N >> K;

	vector<int> position(100001, -1);
	position[N] = 0;
	
	queue<int> Q;
	Q.push(N);

	while (position[K] != -1) {
		int cur = Q.front();
		Q.pop();
		for (int next : {cur - 1, cur + 1, 2 * cur}) {
			if (next < 0 || next > 100000) continue;
			if (position[next] != -1) continue;
			position[next] = position[cur] + 1;
			Q.push(next);
		}
	}

	cout << position[K];

	return 0;
}