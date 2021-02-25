#include<iostream>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<vector>

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

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

int main(){
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

	    cout << "OK" << endl;
	    return 0;
}
