#include <iostream>
using namespace std;
typedef long long ll;

ll memo[40][2] = { {1,0}, {0, 1} };

int main(void) {

	for (int i = 2; i <= 40; i++) {
		memo[i][0] = memo[i - 1][0] + memo[i - 2][0];
		memo[i][1] = memo[i - 1][1] + memo[i - 2][1];
	}

	int T;	//test case
	cin >> T;

	int N;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << memo[N][0] << " " << memo[N][1] << endl;
	}

	return 0;
}