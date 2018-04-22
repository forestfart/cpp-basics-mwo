#include <iostream>

using namespace std;

double fun1() {
    double f = 0;
    const double df = 0.1;
   // while (f != 1.0) {
   //     //...
   //     f += df;
   //     cout << "f = " << f << endl;
   // }

    return f;
}


int main()
{
    cout << "fun1() = " << fun1() << endl;

    cout << "sizee of float = " << sizeof(float) << endl;
    cout << "sizee of double = " << sizeof(double) << endl;
    cout << "sizee of longdouble = " << sizeof(long double) << endl;


    return 0;
}
