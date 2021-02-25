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

Rational operator + (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
				lhs.Denominator() * rhs.Denominator()
	};
}

bool operator == (const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() == rhs.Numerator() &&
			lhs.Denominator() == rhs.Denominator();
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
	return {
			lhs.Numerator() * rhs.Denominator(),
			lhs.Denominator() * rhs.Numerator()
	};
}

int main(){
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
