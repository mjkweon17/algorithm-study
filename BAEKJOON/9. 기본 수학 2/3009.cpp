#include <iostream>
using namespace std;

int main(void) {

	int vertex[4][2];

	for (int i = 0; i < 3; i++) {
		cin >> vertex[i][0] >> vertex[i][1];
	}

	if (vertex[0][0] == vertex[1][0]) {
		vertex[3][0] = vertex[2][0];
	}
	else if (vertex[0][0] == vertex[2][0]) {
		vertex[3][0] = vertex[1][0];
	}
	else {
		vertex[3][0] = vertex[0][0];
	}

	if (vertex[0][1] == vertex[1][1]) {
		vertex[3][1] = vertex[2][1];
	}
	else if (vertex[0][1] == vertex[2][1]) {
		vertex[3][1] = vertex[1][1];
	}
	else {
		vertex[3][1] = vertex[0][1];
	}

	cout << vertex[3][0] << " " << vertex[3][1];

	return 0;
}