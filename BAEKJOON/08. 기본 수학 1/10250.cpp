#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int T;
	cin >> T; //테스트 케이스

	int H, W, N; //호텔의 층 수, 각 층의 방 수, 몇 번째 손님
	int floor;	//층수
	int num;	//호수

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		num = ceil((double)N / H);
		if (N % H) {
			floor = N - (num - 1) * H;
		}
		else {
			floor = H;
		}
		cout << floor;
		cout.fill('0');
		cout.width(2);
		cout << num << endl;;
	}

	return 0;
}