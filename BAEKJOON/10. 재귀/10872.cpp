#include <iostream>
using namespace std;

int factorial(int num) {

	if (num == 1 || num == 0) {
		return 1;
	}
	else {
		return factorial(num - 1) * num;
	}
}

int main(void) {

	int N;
	cin >> N;

	cout << factorial(N);

	return 0;
}