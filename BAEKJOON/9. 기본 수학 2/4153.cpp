#include <iostream>
using namespace std;

int main(void) {

	int side[3] = { 0, };

	while (true) {
		cin >> side[0] >> side[1] >> side[2];
		if (side[0] == 0 && side[1] == 0 && side[2] == 0) {
			break;
		}

		int longest = side[0];
		int longest_index = 0;
		if (longest < side[1]) {
			longest = side[1];
			longest_index = 1;
		}
		if (longest < side[2]) {
			longest = side[2];
			longest_index = 2;
		}

		bool is_right_triangle = false;

		switch (longest_index) {
		case 0:
			if (side[1] * side[1] + side[2] * side[2] == side[0] * side[0]) {
				is_right_triangle = true;
			}
			break;
		case 1:
			if (side[0] * side[0] + side[2] * side[2] == side[1] * side[1]) {
				is_right_triangle = true;
			}
			break;
		case 2:
			if (side[1] * side[1] + side[0] * side[0] == side[2] * side[2]) {
				is_right_triangle = true;
			}
			break;
		}

		if (is_right_triangle) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}

	return 0;
}