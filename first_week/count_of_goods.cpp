#include<iostream>

using namespace std;

/*
 * 100 110 120 5 10		-	100
 * 115 110 120 5 10		-	109.25
 * 150 110 120 5 12.5	-	131.25
 * 100 80 100 5 10		-	95
 */
		// SOLUTION
/*
if (n > b) {
	n *= (1 - y / 100);
} else if (n > a) {
	n *= (1 - x / 100);
}
cout << n;
*/
int main(){
	double N, A, B, X, Y;

	cin >> N >> A >> B >> X >> Y;

	if (A < B) {
		if (N > A && N <= B) {
			cout << N - (N * (X / 100));

		} else if (N > B) {
			cout << N - (N * (Y / 100));

		} else {
			cout << N;
		}
	}

	return 0;
}
