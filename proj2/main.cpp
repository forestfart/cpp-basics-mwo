#include <iostream>

using namespace std;

void swap2Ints(int *x, int *y)
{
    int wsk = *x;
    *x = *y;
    *y = wsk;
}

int main()
{
    int x = 1, y = 2;

    cout << "x = " << x << ", y = " << y << endl;
    swap2Ints(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
