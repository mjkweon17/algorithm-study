#include <iostream>
using namespace std;

int main(void)
{

    int year;
    int leap = 0;

    cin >> year;

    if (year % 4 == 0)
    {
        if(year % 100 == 0){
            if(year % 400 == 0) {
                leap = 1;
            }
        }
        else {
            leap = 1;
        }
    }

    cout << leap;

    return 0;
}