#include <iostream>

using namespace std;

void swap2Ints(int *pA, int *pB)
{
    int wsk = *pA;
    *pA = *pB;
    *pB = wsk;
} // na kartkowce bedzie trzeba opisac co bedzie wynikiem dzialania roznych wersji
  // prawidłowy wynik
  // double *d[3] - tablica wskaznikow
  // double *(*p4)[3] - wskaznik do tablicy 3 elementowej zwracający wskaznik tej tablicy - sprawdzić to

int main()
{
    int x = 1, y = 2;

    cout << "x = " << x << ", y = " << y << endl;
    swap2Ints(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
