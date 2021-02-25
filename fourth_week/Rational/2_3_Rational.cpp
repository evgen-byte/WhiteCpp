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

bool operator == (const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() == rhs.Numerator()
			&& lhs.Denominator() == rhs.Denominator();
}
Rational operator + (const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
			lhs.Denominator() * rhs.Denominator());
}
Rational operator - (const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
			lhs.Denominator() * rhs.Denominator());
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Numerator(),
					lhs.Denominator() * rhs.Denominator());
}
Rational operator / (const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator(),
			lhs.Denominator() * rhs.Numerator());
}


int main() {
	{
	        Rational a(2, 3);
	        Rational b(4, 3);
	        Rational c = a * b;
	        bool equal = c == Rational(8, 9);
	        if (!equal) {
	            cout << "2/3 * 4/3 != 8/9" << endl;
	            return 1;
	        }
	    }

	    {
	        Rational a(5, 4);
	        Rational b(15, 8);
	        Rational c = a / b;
	        bool equal = c == Rational(2, 3);
	        if (!equal) {
	            cout << "5/4 / 15/8 != 2/3" << endl;
	            return 2;
	        }
	    }

	    cout << "OK" << endl;

    return 0;
}
