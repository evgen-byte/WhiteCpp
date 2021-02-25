#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
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

istream& operator >> (istream& stream, Rational& ratio) {
	int d, n;
	char c;
	stream >> n >> c >> d;
	if (stream && c == '/') {
		ratio = Rational(n, d);
	}
	return stream;
}


ostream& operator << (ostream& stream, const Rational& ratio) {
	stream << ratio.Numerator() << "/"
			<< ratio.Denominator();
	return stream;
}


int main(){
	 {
	        ostringstream output;
	        output << Rational(-6, 8);
	        if (output.str() != "-3/4") {
	            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
	            return 1;
	        }
	    }

	    {
	        istringstream input("5/7");
	        Rational r;
	        input >> r;
	        bool equal = r == Rational(5, 7);
	        if (!equal) {
	            cout << "5/7 is incorrectly read as " << r << endl;
	            return 2;
	        }
	    }

	    {
	        istringstream input("5/7 10/8");
	        Rational r1, r2;
	        input >> r1 >> r2;
	        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
	        if (!correct) {
	            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
	            return 3;
	        }

	        input >> r1;
	        input >> r2;
	        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
	        if (!correct) {
	            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
	            return 4;
	        }
	    }

	    cout << "OK" << endl;
	    return 0;
}
