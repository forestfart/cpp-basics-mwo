#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class Rational
{
    int numer;
    int denom;
    int gcdND;

    void initialize(int numerator, int denominator);
public:
    Rational(int numerator, int denominator = 1);
    virtual ~Rational() {}
    Rational(const Rational & copy);

    Rational & operator= (Rational const& other);
    Rational & operator= (int i);

    int numerator() const { return numer; }
    int denominator() const { return denom; }

    static const Rational normalize(Rational const& other);
    static const Rational normalized(int numerator, int denominator);

    Rational operator+ (Rational const& other) const;
    Rational operator- (Rational const& other) const;
    Rational operator* (Rational const& other) const;
    Rational operator/ (Rational const& other) const;

    Rational operator+ () const;
    Rational operator- () const;

    bool operator== (Rational const& other) const;
    bool operator>= (Rational const& other);
    bool operator<= (Rational const& other);
    bool operator> (Rational const& other);
    bool operator< (Rational const& other);

    friend std::ostream & operator<< (std::ostream &, const Rational &);
    friend std::istream & operator>> (std::istream &, Rational &);
};

Rational operator+ (Rational const& r, int i);
Rational operator+ (int i, Rational const& r);

Rational operator- (Rational const& r, int i);
Rational operator- (int i, Rational const& r);

Rational operator* (Rational const& r, int i);
Rational operator* (int i, Rational const& r);

Rational operator/ (Rational const& r, int i);
Rational operator/ (int i, Rational const& r);



int gcd (int a, int b);

Rational::Rational(int numerator, int denominator)
{
    if (denominator == 0)
        throw new std::invalid_argument("Denominator cannot be 0!");

    initialize(numerator, denominator);
}

Rational::Rational(const Rational & copy)
{
    initialize(copy.numer, copy.denom);
}

Rational & Rational::operator= (Rational const& other)
{
    this->numer = other.numer;
    this->denom = other.denom;
    return *this;
}

Rational & Rational::operator= (int i)
{
    this->numer = i;
    this->denom = 1;
    return *this;
}

const Rational Rational::normalize(Rational const & other)
{
    int rgcd = gcd(other.numer, other.denom);
    return Rational(other.numer / rgcd, other.denom / rgcd);
}

const Rational Rational::normalized(int numerator, int denominator)
{
    int rgcd = gcd(numerator, denominator);
    return Rational(numerator / rgcd, denominator / rgcd);
}

Rational Rational::operator+ (Rational const & other) const
{
    int resDenom = this->denom * other.denom;
    int resNumer = this->numer * other.denom + other.numer * this->denom;

    return normalized(resNumer, resDenom);
}

Rational Rational::operator- (Rational const & other) const
{
    int resDenom = this->denom * other.denom;
    int resNumer = this->numer * other.denom - other.numer * this->denom;

    return normalized(resNumer, resDenom);
}

Rational Rational::operator* (const Rational & other) const
{
    int resNumer = this->numer * other.numer;
    int resDenom = this->denom * other.denom;

    return normalized(resNumer, resDenom);
}

Rational Rational::operator/ (Rational const& other) const
{
    int resNumer = this->numer * other.denom;
    int resDenom = this->denom * other.numer;

    return normalized(resNumer, resDenom);
}

Rational Rational::operator+ () const
{
    return Rational(this->numer, this->denom);
}

Rational Rational::operator- () const
{
    return Rational(-1 * this->numer, this->denom);
}

bool Rational::operator== (Rational const & other) const
{
    return (this->numer * other.denom == this->denom * other.numer);
}

bool Rational::operator>= (Rational const& other)
{
    return (*this == other) || (*this > other);
}

bool Rational::operator<= (Rational const& other)
{
    return (*this == other) || (*this < other);
}

bool Rational::operator> (Rational const& other)
{
    return (this->numer * other.denom > this->denom * other.numer);
}

bool Rational::operator< (Rational const& other)
{
    return (this->numer * other.denom < this->denom * other.numer);
}

void Rational::initialize(int numerator, int denominator)
{
    if (denominator < 0) {
        this->numer = -numerator;
        this->denom = -denominator;
    } else {
        this->numer = numerator;
        this->denom = denominator;
    }
    this->gcdND = gcd(this->numer, this->denom);
}

Rational operator+ (Rational const& r, int i)
{
    return r + Rational(i);
}

Rational operator+ (int i, Rational const& r)
{
    return operator+(r, i);
}

Rational operator- (Rational const& r, int i)
{
    return r - Rational(i);
}

Rational operator- (int i, Rational const& r)
{
    return operator-(r, i);
}

Rational operator* (Rational const& r, int i)
{
    return r - Rational(i);
}

Rational operator* (int i, Rational const& r)
{
    return operator*(r, i);
}

Rational operator/ (Rational const& r, int i)
{
    return r / Rational(i);
}

Rational operator/ (int i, Rational const& r)
{
    return operator/(r, i);
}

std::ostream & operator<< (std::ostream & out, const Rational & r)
{
    std::stringstream rAsString;

    if (r.denom == 1) {
        rAsString << r.numer;
    }
    else {
        rAsString << r.numer << "/" << r.denom;
    }

    if (r.numer < 0) {
        out << "(" << rAsString.str() << ")";
    } else {
        out << rAsString.str();
    }

    return out;
}

std::istream & operator >> (std::istream & in, Rational & r)
{
    in >> r.numer ;
    in.ignore(1);
    in >> r.denom;

    return in;
}

int gcd ( int a, int b)
{
    int c;

    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }

    return b;
}

void areEqual()
{
    Rational r1(1,2), r2(3, 6), r3(1, 3), r5(18, 6);
    Rational r4 = 3; //Rational(int)

    if (r1 == r2) {
        cout << r1 << " = " << r2 << endl;
    } else {
        cout << r1 << " != " << r2 << endl;
    }


    if (r2 == r3) {
        cout << r2 << " = " << r3 << endl;
    } else {
        cout << r2 << " != " << r3 << endl;
    }

    if (r4 == r5) {
        cout << r4 << " = " << r5 << endl;
    } else {
        cout << r4 << " !=" << r5 << endl;
    }
}

void assignment()
{
    Rational r1(3,4), r2(1,5);
    cout << "r1 = " << r1 << ", r2 = " << r2 << endl;
    cout << "r2 = r1" << endl;
    r2 = r1;
    cout << "r2 = " << r2 << ", r1 = " << r1 << endl;
}

void addition()
{
   Rational r1(2,3), r2(2, 11), r3(1, -3), r4(3), r5(18, 6);

   cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
   cout << r1 << " + " << r3 << " = " << r1 + r3 << endl;
   cout << r2 << " + " << r5 << " = " << r2 + r5 << endl;

   cout << -r2 << " + " << r4 << " = " << -r2 + r5 << endl;

   cout << r2 << " + " << 3 << " = " << r2 + 3 << endl;
   cout << 3 << " + " << r2 << " = " << 3 + r2 << endl;
}

void substraction()
{
   Rational r1(2,3), r2(2, 11), r3(1, -3), r4(3), r5(18, 6);

   cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
   cout << r1 << " - " << r3 << " = " << r1 - r3 << endl;
   cout << r2 << " - " << r5 << " = " << r2 - r5 << endl;
}

void multiplication()
{
    Rational r1(2,3), r2(2, 11), r3(1, -3), r4(3), r5(18, 6);

    cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
    cout << r1 << " * " << r3 << " = " << r1 * r3 << endl;
    cout << r2 << " * " << r5 << " = " << r2 * r5 << endl;
}

void division()
{
    Rational r1(2,3), r2(2, 11), r3(1, -3), r4(3), r5(18, 6);

    cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
    cout << r1 << " / " << r3 << " = " << r1 / r3 << endl;
    cout << r2 << " / " << r5 << " = " << r2 / r5 << endl;
}

void combined()
{
    Rational r2(2, 11), r3(1, -3), r5(18, 6);
    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;

    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    cout << 3 << " + " << r2 << " * " <<  r3 << " = " << res1 << endl;
    cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << res2 << endl;
    cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/" <<
            "(" << r5 << " - " << r3 << ")" << " = " << res3 << endl;
}

int main()
{
    areEqual();
    cout << endl;
    assignment();
    cout << endl;
    addition();
    cout << endl;
    substraction();
    cout << endl;
    multiplication();
    cout << endl;
    division();
    cout << endl;
    combined();

    return 0;
}

