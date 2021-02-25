#include <iostream>

using namespace std;

		// RECURSION

int Factorial(int x) {
	if (x <= 1) {
		return 1;
	} else {
		return x * Factorial(x - 1); // вычисляем факториал от х-1 и умножаем на х
	}
}


int Factorial(int n) {
	int factor = 1;
	if (n > 0) {
		for (size_t i = 1; i <= n; ++i) {
			factor *= i;
		}
		return factor;
	}
	return factor;
}

int main() {
	int n;
	cin >> n;
	cout << Factorial(n);

  return 0;
}
