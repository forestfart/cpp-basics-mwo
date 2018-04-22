#include <iostream>

using namespace std;

void swap2Ints(int *pA, int *pB)
{
    int wsk = *pA;
    *pA = *pB;
    *pB = wsk;
} // na kartkowce bedzie trzeba opisac co bedzie wynikiem dzialania roznych wersji
  // prawidłowy wynik
int main()
{
    int x = 1, y = 2;

    cout << "x = " << x << ", y = " << y << endl;
    swap2Ints(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
