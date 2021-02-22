#include <iostream>
using namespace std;

int Fibonacci(int num);

int main(void) {

	int n;
	cin >> n;

	cout << Fibonacci(n);

	return 0;
}

int Fibonacci(int num) {
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}

	return Fibonacci(num - 1) + Fibonacci(num - 2);
}