#include <iostream>
using namespace std;

int main(void) {

	int N; //배달량
	cin >> N;
	int temp = N;	//배달량 임시 저장

	int num = 0; //3kg, 5kg 봉지 개수
	int num3 = 0;	//3kg 봉지 개수
	int num5 = 0;	//5kg 봉지 개수

	switch (N % 5) {
	case 0:
		num5 += temp / 5;
		break;
	case 1:
		num3 += 2;
		temp -= 3 * 2;
		num5 += temp / 5;
		break;
	case 2:
		num3 += 4;
		temp -= 3 * 4;
		num5 += temp / 5;
		break;
	case 3:
		num3 += 1;
		temp -= 3 * 1;
		num5 += temp / 5;
		break;
	case 4:
		num3 += 3;
		temp -= 3 * 3;
		num5 += temp / 5;
		break;
	}

	if (num5 >= 0) {
		num = num3 + num5;
	}
	else {
		num = -1;
	}

	cout << num;

	return 0;
}