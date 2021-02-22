#include <iostream>
using namespace std;

int main(void)
{
	int A, B;

	while (true)
	{
		cin >> A >> B;
		if (!(A >= 10000 || A <= 10000 || B >= 10000 || B <= 10000))
			break;
	}

	if (A > B)
	{
		cout << '>';
	}
	else if (A < B)
	{
		cout << '<';
	}
	else
	{
		cout << "==";
	}

	return 0;
}