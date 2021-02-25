#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int Nod(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return Nod(b, a % b);
	}
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int new_numerator, int new_denominator) {
		const int nod = Nod(new_numerator, new_denominator);

		numerator = new_numerator / nod;
		denominator = new_denominator / nod;

		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}

	}
	int Numerator() const {
		return numerator;
	}
	int Denominator() const {
		return denominator;
	}
private:
	int numerator;
	int denominator;
};

int main(){
	 {
	        const Rational r(3, 10);
	        if (r.Numerator() != 3 || r.Denominator() != 10) {
	            cout << "Rational(3, 10) != 3/10" << endl;
	            return 1;
	        }
	    }

	    {
	        const Rational r(8, 12);
	        if (r.Numerator() != 2 || r.Denominator() != 3) {
	            cout << "Rational(8, 12) != 2/3" << endl;
	            return 2;
	        }
	    }

	    {
	        const Rational r(-4, 6);
	        if (r.Numerator() != -2 || r.Denominator() != 3) {
	            cout << "Rational(-4, 6) != -2/3" << endl;
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

	    cout << "OK" << endl;
	    return 0;
}
