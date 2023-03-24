#include <iostream>
using namespace std;

bool check666(int num);

int main(void) {

	int N;
	cin >> N;

	int num = 0;
	int count = 0;

	while (true) {
		num++;
		if (check666(num)) {
			count++;
			if (count == N) {
				break;
			}
		}
	}
	

	cout << num;

	return 0;
}

bool check666(int num) {

	int count = 0;

	while (num) {
		if (num % 10 == 6) {
			count++;
			if (count == 3) {
				break;
			}
		}
		else {
			if (count != 0) {
				count = 0;
			}
		}
		num /= 10;
	}

	if (count == 3) {
		return true;
	}

	return false;
}