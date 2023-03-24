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
		result = addStr(B, A);
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
	int temp = 0;	//str1�� str2�� i��° �ڸ��� ���� ������ ����
	int temp1 = 0;	//���� temp�� 10 �̻��� �� 10�� ������ ����

	for (int i = 0; i < str1.length(); i++) {

		if (i >= str2.length()) {	//str2�� �� �̻� ���꿡 �������� ������
			temp = atoi(str1[str1.length() - 1 - i]) + temp1;
		}
		else {
			temp = atoi(str1[str1.length() - 1 - i])
				+ atoi(str2[str2.length() - 1 - i]) + temp1;
		}

		if (temp >= 10) {
			temp -= 10;
			temp1 = 1;
		}
		else {
			temp1 = 0;
		}

		result = itoa(temp) + result;
		
		if (i == str1.length() - 1 && temp1 == 1) {
			result = itoa(1) + result;
		}
	}

	return result;
}