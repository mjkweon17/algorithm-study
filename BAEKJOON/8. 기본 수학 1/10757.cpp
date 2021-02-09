#include <iostream>
#include <string>
using namespace std;

int atoi(char ch);
char itoa(int num);
string addStr(string str1, string str2);

int main(void) {

	string A, B;
	cin >> A >> B;

	string result = "";

	if (A.length() >= B.length()) {
		result = addStr(A, B);
	}
	else {
		result = addStr(B, B);
	}

	cout << result;

	return 0;
}

int atoi(char ch) {
	return ch - '0';
}

char itoa(int num) {
	return num + '0';
}

string addStr(string str1, string str2) {
	
	string result = "";
	int temp = 0;	//str1과 str2의 i번째 자리의 합을 저장할 변수
	int temp1 = 0;	//만약 temp가 10 이상일 때 10을 저장할 변수

	for (int i = 0; i < str1.length(); i++) {

		if (i >= str2.length()) {	//str2가 더 이상 연산에 참여하지 않으면
			temp = atoi(str1[str1.length() - 1 - i]) + temp1;
			temp1 = 0;
		}
		else {
			temp = atoi(str1[str1.length() - 1 - i])
				+ atoi(str2[str2.length() - 1 - i]) + temp1;
			temp1 = 0;
		}

		if (temp > 9) {	//temp가 두 자리수면 

			int j = i;
			while (true) {
				j++;
				if (j + 1 == str1.length()) {

				}
				else {
					str1[str1.length() - 1 - j] += 1;
				}
			}





			if (i + 1 == str1.length()) {	//현재 연산하는 자리수가 str1의 자리수랑 같으면
				result = "1" + itoa(temp - 10) + result;
			}



			else {
				result = itoa(temp - 10) + result;

				int j = i;
				while (true) {	//조건 하나 더 추가하자
					if (str1[str1.length() - 1 - j] != '9') {
						str1[str1.length() - 1 - j] += 1;
					}
					else {
						j++;
					}
				}
			}
		}





		else {	//temp가 1자리 수면
			result = itoa(temp) + result;
			temp1 = 0;
		}
	}

	return result;
}