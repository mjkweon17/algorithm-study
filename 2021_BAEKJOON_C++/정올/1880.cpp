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

	string decrypion_key;	//복호화 키
	getline(cin, decrypion_key);

	string cyphertext;	//암호문
	getline(cin, cyphertext);
	string plain_text = cyphertext;

	int temp;	//연산할 때 임시로 숫자 저장할 변수
	for (int i = 0; i < cyphertext.length(); i++) {
		if (cyphertext[i] >= 'A' && cyphertext[i] <= 'Z') {	//대문자일 때
			plain_text[i] = decrypion_key[cyphertext[i] - 'A'] - 'a' + 'A';
		}
		else if (cyphertext[i] >= 'a' && cyphertext[i] <= 'z') {	//소문자일 때
			plain_text[i] = decrypion_key[cyphertext[i] - 'a'];
		}
		else continue;	//대문자도 소문자도 아닐 때. 여기서는 공백문자가 될 수 있음
	}

	cout << plain_text;

	return 0;
}