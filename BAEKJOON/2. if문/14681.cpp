#include <iostream>
using namespace std;

int main(void)
{

    int x, y;
    int quadrant;

    cin >> x >> y;

    if (x > 0)
    {
        if (y > 0)
        {
            quadrant = 1;
        }
        else if (y < 0)
        {
            quadrant = 4;
        }
    }
    else if (x < 0)
    {
        if (y > 0)
        {
            quadrant = 2;
        }
        else if (y < 0){
            quadrant = 3;
        }
    }

    cout << quadrant;

    return 0;
}