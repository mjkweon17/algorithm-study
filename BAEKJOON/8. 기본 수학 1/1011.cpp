#include <iostream>
using namespace std;

int babylonian(long long distance);

int main(void) {

	int T;	//테스트 케이스
	cin >> T;

	for (int i = 0; i < T; i++) {

		long long x, y;	//현재 위치, 목표 위치
		cin >> x >> y;
		long long distance = y - x;

		int count = 0;	//이동 횟수

		int n = babylonian(distance); //최대 이동 거리
		
		count += 2 * n - 1;
		
		int left = distance - n * n;
		
		if (left > n) {
			count += 2;
		}
		else if (left > 0) {
			count += 1;
		}
		
		cout << count << endl;
	}

	return 0;
}

int babylonian(long long distance) {
	long long x = distance;
	long long y = 1;
	while (x > y) {
		x = (x + y) / 2;
		y = distance / x;
	}
	return x;
}