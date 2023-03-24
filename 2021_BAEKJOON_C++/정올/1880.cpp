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

	string decrypion_key;	//��ȣȭ Ű
	getline(cin, decrypion_key);

	string cyphertext;	//��ȣ��
	getline(cin, cyphertext);
	string plain_text = cyphertext;

	int temp;	//������ �� �ӽ÷� ���� ������ ����
	for (int i = 0; i < cyphertext.length(); i++) {
		if (cyphertext[i] >= 'A' && cyphertext[i] <= 'Z') {	//�빮���� ��
			plain_text[i] = decrypion_key[cyphertext[i] - 'A'] - 'a' + 'A';
		}
		else if (cyphertext[i] >= 'a' && cyphertext[i] <= 'z') {	//�ҹ����� ��
			plain_text[i] = decrypion_key[cyphertext[i] - 'a'];
		}
		else continue;	//�빮�ڵ� �ҹ��ڵ� �ƴ� ��. ���⼭�� ���鹮�ڰ� �� �� ����
	}

	cout << plain_text;

	return 0;
}