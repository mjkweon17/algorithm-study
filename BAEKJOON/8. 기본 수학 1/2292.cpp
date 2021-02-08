#include <iostream>
using namespace std;

int main(void) {

	int N;
	cin >> N;

	int count = 0;
	int biggest = 1;	//count + 1 번째 둘레에서 가장 큰 수 저장

	while (true) {
		biggest += 6 * count;
		count++;
		if (biggest >= N) {
			break;
		}
	}

	cout << count;

	return 0;
}