#include <iostream>
using namespace std;

int main(void) {

	int dice1, dice2, dice3;
	cin >> dice1 >> dice2 >> dice3;

	if (dice1 == dice2 && dice2 == dice3) {	//모두 같음
		cout << 10000 + dice1 * 1000;
	}
	else if (dice1 != dice2 && dice2 != dice3 && dice1 != dice3) {	//모두 다름
		if (dice1 > dice2) {
			if (dice1 > dice3) {	//1이 제일 큼
				cout << dice1 * 100;
			}
			else {	//3이 제일 큼
				cout << dice3 * 100;
			}
		}
		else {	
			if (dice2 > dice3) {	//2가 제일 큼
				cout << dice2 * 100;
			}
			else {	//3이 제일 큼
				cout << dice3 * 100;
			}
		}
	}
	else {	//2개가 같음
		if (dice1 == dice2) {
			cout << 1000 + dice1 * 100;
		}
		else {
			if (dice1 == dice3) {
				cout << 1000 + dice1 * 100;
			}
			else {
				cout << 1000 + dice2 * 100;
			}
		}
	}

	return 0;
}