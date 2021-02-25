#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	double a, b, c, d;
	cin >> a >> b >> c;

	d = (b * b) - (4 * a * c);
	cout << d << endl;

	if (d > 0) {
		if (a == 0) {
			cout << -(c / b);
		} else {
			cout << (-b + sqrt(d)) / (2 * a) << " ";
			cout << (-b - sqrt(d)) / (2 * a);
		}

	} else if (d == 0) {
		if (b == 0) {
			cout << "";
		} else {
			cout << -(b / (2 * a));
		}

	} else {
		cout << "";
	}

	return 0;
}
