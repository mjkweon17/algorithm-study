#include <iostream>
using namespace std;

bool is_prime(int num);

int main(void) {

	int M, N;	//M < N
	cin >> M >> N;

	int total = 0;
	int smallest = -1;

	for (int i = M; i <= N; i++) {
		if (is_prime(i)) {	//소수가 맞으면
			if (smallest == -1) {
				smallest = i;
			}
			total += i;
		}
	}

	if (smallest == -1) {
		cout << smallest;
	}
	else {
		cout << total << endl << smallest;
	}

	return 0;
}

bool is_prime(int num) {
	
	if (num == 1) {
		return false;
	}
	if (num == 2) {
		return true;
	}

	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}