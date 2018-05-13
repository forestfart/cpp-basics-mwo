#include <iostream>

using namespace std;

void swap2Ints(int *pA, int *pB)
{
    int wsk = *pA;
    *pA = *pB;
    *pB = wsk;
} // na kartkowce bedzie trzeba opisac co bedzie wynikiem dzialania roznych wersji (kilka definicji) oraz problemy z typami zmiennych
  // zmienne lokalne na stosie, pamiec(obiekty) na stercie, jest jeszcze obszar zmiennych globalnych
  // prawidłowy wynik
  // double *d[3] - tablica wskaznikow
  // double **d[3] - tablica wskaznikow do wskaznikow
  // double *(*p4)[3] - wskaznik do tablicy 3 elementowej zwracający wskaznik tej tablicy - sprawdzić to
  // int *f2(double) - f2 jest funkcją, która ma parametr double i zwraca wskaznik do inta
  // int (*p4)(double) - wskaznik do funkcji p4, ktora ma parametr double i zwraca inta
  // int * f (double(*)(float), int) - funkcja dwuparametrowa. pierwszy jest wskaznikiem do funkcji...
  // ZADANIE DOMOWE: napisac definicje dowolnego wskaznika do funkcji, która to funkcja zwraca wskaznik do funkcji
  // podpowiedź: ... *(*p5)(___)

  // Java: C c1 = new C(); c1.m1();
  // C++:  C *pC = new C; (*pC).m1(); pC->m1();

  // sprawdzic dockera!

  // made with QT Creator

int main()
{
    int x = 1, y = 2;

    cout << "x = " << x << ", y = " << y << endl;
    swap2Ints(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
