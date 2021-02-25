#include<iostream>

using namespace std;

	// SOLUTION
/*int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            cout << i << ' ';
        }
    }
*/
int main(){
	int A, B;
	cin >> A >> B;

	while (A <= B) {
		if (A % 2 == 0) {
			cout << A << " ";
		}
		++A;
	}

	return 0;
}
