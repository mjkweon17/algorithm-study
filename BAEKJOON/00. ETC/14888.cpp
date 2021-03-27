#include <iostream>
using namespace std;

int arr[11];
int oper[4];

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	int N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}	//+ - * /

	return 0;
}