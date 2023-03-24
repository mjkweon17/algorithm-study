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

	int index = 0;	//암호화 키의 인덱스
	for (int i = 0; i <= plain_text.length(); i++) {
		if (index == encryption_key.length()) {	//만약 index가 암호키의 길이와 같으면 초기화
			index = 0;
		}

		if (cyphertext[i] == ' ') {	//공백문자면 변화없음
			index++;
			continue;
		}

		if (cyphertext[i] - encryption_key[index] <= 0) {	//'a' 이전의 문자가 됨
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