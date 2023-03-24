#include <iostream>
using namespace std;

int main(void) {

	int N;
	int cycle = 0;
	int temp_num;
	int new_num;

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	new_num = N;
	
	while (true) {
		if (new_num < 10) {
			temp_num = new_num;
			new_num = new_num * 10 + temp_num;
		}
		else {
			temp_num = new_num / 10 + new_num % 10;
			new_num = new_num % 10 * 10 + temp_num % 10;
		}
		cycle++;
		if (new_num == N) {
			break;
		}
	}

	cout << cycle;

	return 0;
}