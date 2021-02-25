#include <iostream>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<set>
#include<map>
#include<vector>
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
        	num = -numerator / Nod(numerator, denominator);
        	denom = abs(denominator) / Nod(numerator, denominator);

        } else if (numerator < 0 && denominator < 0){
        	num = abs(numerator) / Nod(numerator, denominator);
        	denom = abs(denominator) / Nod(numerator, denominator);

        } else {
        	num = numerator / Nod(numerator, denominator);
        	denom = denominator / Nod(numerator, denominator);
        }
    }
    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return denom;
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

ostream& operator << (ostream& stream, const Rational& rat) {

	stream << rat.Numerator() << '/' << rat.Denominator();
	return stream;
}
istream& operator >> (istream &stream, Rational& rat) {
	int n = 0;
	int d = 0;

	if (stream) {
		stream >> n;
		if (stream.fail()) {
			return stream;
		}

//		char c;
//		stream >> c;
//		bool sym = c == '/';
//		if (!sym) {
//			return stream;
//		}
		if (stream.peek() != '/') {
			return stream;
		}
		stream.ignore(1);
		stream >> d;
		if (stream.fail()) {
			return stream;
		}
		rat = Rational(n, d);
		return stream;
	}
	return stream;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
	double r_num, r_den, l_num, l_den;
	l_num = lhs.Numerator();
	l_den = lhs.Denominator();
	r_num = rhs.Numerator();
	r_den = rhs.Denominator();
	double left_fract = l_num / l_den;
	double right_fract = r_num / r_den;

	if (left_fract > right_fract) {
		return false;
	} else if (left_fract < right_fract) {
		return true;
	}
	return false;
}

int main() {
	{
	        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
	        if (rs.size() != 3) {
	            cout << "Wrong amount of items in the set" << endl;
	            return 1;
	        }

	        vector<Rational> v;
	        for (auto x : rs) {
	            v.push_back(x);
	        }
	        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
	            cout << "Rationals comparison works incorrectly" << endl;
	            return 2;
	        }
	    }

	    {
	        map<Rational, int> count;
	        ++count[{1, 2}];
	        ++count[{1, 2}];

	        ++count[{2, 3}];

	        if (count.size() != 2) {
	            cout << "Wrong amount of items in the map" << endl;
	            return 3;
	        }
	    }
	    {
	    	const set<Rational> rs = {{15, 22}, {8, 3}, {1, 2}, {8, 3}, {18, 9}};
	    	for (auto n : rs) {
	    		cout << n << " ";
	    	}
	    	cout << endl;
	    	if (rs.size() != 4) {
	    		cout << "Wrong set" << endl;
	    		return 4;
	    	}
	    }

	    cout << "OK" << endl;

    return 0;
}
