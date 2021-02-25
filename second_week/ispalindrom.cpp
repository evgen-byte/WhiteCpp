#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool IsPalindrom(string str) {
	string compar;
	for(int i = str.size() - 1; i >= 0; --i) {
		compar.push_back(str[i]);
	}
	if(str == compar) {
		return true;
	}

	return false;
}

int main(){
	string s;
	cin >> s;
	cout << IsPalindrom(s);

	return 0;
}
