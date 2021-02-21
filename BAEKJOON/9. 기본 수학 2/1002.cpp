#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int T;
	int x1, y1, r1, x2, y2, r2;
	double distance;	//조규현과 백승환의 거리

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		if (r2 > r1) {
			int temp = r2;
			r2 = r1;
			r1 = temp;
		}
		
		if (distance < r1 + r2 && distance > r1 - r2) {
			cout << 2 << endl;
		}
		else if (distance == r1 + r2 || distance = r1 - r2) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}