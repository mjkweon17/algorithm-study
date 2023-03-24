#include <iostream>
using namespace std;

int main(void) {

	int a, b;

	cin >> a >> b;
	if (a <= 0 || a >= 10 || b <= 0 || b >= 10) {
		return 0;
	}

	cout << fixed; //소수점을 고정시켜 출력
	cout.precision(15); //소수점 15자리까지 출력. 만약 fixed를 하지 않았다면 소수점을 포함한 15자리 출력
	cout << (double)a / b;
	cout.unsetf(ios::fixed); //소수점 고정 해제

	return 0;
}