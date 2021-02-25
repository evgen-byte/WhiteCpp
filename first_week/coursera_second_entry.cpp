#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	cin >> s;

	int result = -2; // текущий ответ
	// елси f не встретится ни разу, он останется равным -2

	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == 'f') {

			if (result == -2) {
				result = -1;
			}
		} else if (result == -1) {
			result = i;
			break;
		}
	}
	cout << result;

	return 0;
}
