#include<iostream>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<exception>
#include<stdexcept>

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
			// бросок в случае нулевого знаменателя
		if (denominator == 0) {
			throw invalid_argument("zero denominator!");
		}

		else if (denominator < 0) {
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
			// деление
Rational operator / (const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() * rhs.Numerator() == 0) {
		throw domain_error("division by zero");
	}
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

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

int main(){
	 try {
	        Rational r(1, 0);
	        cout << "Doesn't throw in case of zero denominator" << endl;
	        return 1;
	    } catch (invalid_argument&) {

	    }

	    try {
	        auto x = Rational(1, 2) / Rational(0, 1);
	        cout << "Doesn't throw in case of division by zero" << endl;
	        return 2;
	    } catch (domain_error&) {
	    }

	    cout << "OK" << endl;
	    return 0;
}
