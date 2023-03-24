#include <iostream>
using namespace std;

int main(void) {

	int rest[42] = { 0, };
	int num;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> num;
		rest[num % 42] += 1;
	}

	int count = 0;

	for (int i = 0; i < 42; i++) {
		if (rest[i] != 0){
			count++;
		}
	}

	cout << count;

	return 0;
}