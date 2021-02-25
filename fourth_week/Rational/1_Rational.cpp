#include <iostream>
#include<cmath>
using namespace std;

int Nod(int a, int b) {
	a = abs(a);
	b = abs(b);
	while(a > 0 && b > 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return a + b;
}

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator >= 0 && denominator < 0) {
        	num = -numerator;
        	denom = abs(denominator);
        } else if (numerator < 0 && denominator < 0){
        	num = abs(numerator);
        	denom = abs(denominator);
        } else {
        	num = numerator;
        	denom = denominator;
        }
    }

    int Numerator() const {
        return num / Nod(num, denom);
    }

    int Denominator() const {
        return denom / Nod(num, denom);
    }

private:
    int num;
    int denom;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl; // нод - 1
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl; // нод - 4
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl; // нод - 2
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }
   {
           const Rational r(-4, -6);
           if (r.Numerator() != 2 || r.Denominator() != 3) {
               cout << "Rational(-4, -6) != -2/-3" << endl;
               return 3;
           }
       }
    {
              const Rational r(0, -3);
              if (r.Numerator() != 0 || r.Denominator() != 1) {
                  cout << "Rational(0, -3) != 5/3" << endl;
                  return 3;
              }
          }

    cout << "OK" << endl;
    return 0;
}
