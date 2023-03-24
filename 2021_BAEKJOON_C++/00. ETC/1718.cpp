#include <iostream>
#include <string>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {

	init();

	string plain_text;
	string encryption_key;
	string cyphertext;

	getline(cin, plain_text);
	getline(cin, encryption_key);
	cyphertext = plain_text;

	int index = 0;	//��ȣȭ Ű�� �ε���
	for (int i = 0; i <= plain_text.length(); i++) {
		if (index == encryption_key.length()) {	//���� index�� ��ȣŰ�� ���̿� ������ �ʱ�ȭ
			index = 0;
		}

		if (cyphertext[i] == ' ') {	//���鹮�ڸ� ��ȭ����
			index++;
			continue;
		}

		if (cyphertext[i] - encryption_key[index] <= 0) {	//'a' ������ ���ڰ� ��
			cyphertext[i] = 'z' - (encryption_key[index] - cyphertext[i]);
		}
		else {
			cyphertext[i] = 'a' - 1 + cyphertext[i] - encryption_key[index];
		}
		index++;
	}

	cout << cyphertext;

	return 0;
}