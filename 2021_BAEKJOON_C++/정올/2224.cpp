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

	char plain[26] = { 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' };
	char cypher[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	string cyphertext;
	getline(cin, cyphertext);
	string plain_text = cyphertext;

	for (int i = 0; i < cyphertext.length(); i++) {
		if (cyphertext[i] < 'A' || cyphertext[i] > 'Z') continue;
		int index;
		for (index = 0; index < 26; index++) {
			if (cyphertext[i] == cypher[index]) {
				break;
			}
		}
		plain_text[i] = plain[index];
	}

	cout << plain_text;

	return 0;
}