#include <iostream>
#include <vector>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	int N;
	cin >> N;

	vector<int> vec;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	int v;
	cin >> v;
	
	cout << count(vec.begin(), vec.end(), v);

	return 0;
}