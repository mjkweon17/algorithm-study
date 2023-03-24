#include <iostream>
using namespace std;

int main(void) {

	int A, B, V;	//올라가는 길이, 내려가는 길이, 막대 길이
	cin >> A >> B >> V;

	int day;

	if ((V - A) % (A - B)) {
		day = (V - A) / (A - B) + 2;
	}
	else {
		day = (V - A) / (A - B) + 1;
	}

	cout << day;

	return 0;
}