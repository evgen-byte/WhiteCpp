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
			throw invalid_argument("Invalid argument");
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
		throw domain_error("Division by zero");
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
	string x, y;
	char c;
	cin >> x >> c >> y;
	istringstream input(x + ' ' + y);

	Rational r1, r2;
	try {
		input >> r1 >> r2;

	if (c == '+') {
		cout << r1 + r2;
	} else if (c == '-') {
		cout << r1 - r2;
	} else if (c == '*') {
		cout << r1 * r2;
	} else if (c == '/') {
		try {
			cout << r1 / r2;
		} catch (domain_error& er) {
			cout << er.what() << endl;
		}
	}
	} catch (invalid_argument& inv) {
		cout << inv.what() << endl;
	}


	return 0;
}
// 1/2 + 1/3
// 1/2 + 5/0
// 4/5 / 0/8
