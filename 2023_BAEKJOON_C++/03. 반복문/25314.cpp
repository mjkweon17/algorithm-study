#include <iostream>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {

	init();

	int N;
	cin >> N;
	
	int long_num = N / 4;
	if (N % 4) long_num++;

	for (int i = 0; i < long_num; i++) {
		cout << "long ";
	}
	cout << "int";

	return 0;
}