#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctype.h>
using namespace std;

void Print(const vector<string>& c) {
	for (const auto& num : c) {
		cout << num << " ";
	}
	cout << endl;
}

bool Compar(string a, string b) {
	string s1, s2;
	for (char a1 : a) {
		s1 += tolower(a1);
		}
	for (char b1 : b) {
		s2 += tolower(b1);
	}

	return (s1 < s2);

}
int main(){

	int n;
	cin >> n;
	vector<string> c(n);

	for (auto& ch : c) {
		cin >> ch;
	}

	sort(begin(c), end(c), Compar);
	Print(c);

	return 0;
}
