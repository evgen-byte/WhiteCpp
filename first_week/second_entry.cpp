#include<iostream>
#include<string>

using namespace std;
/*
 * comfort
 * coffee
 * car
 */
int main(){
	string st;
	cin >> st;
	int num = 0;
	int position = 0;

	for (size_t i = 0; i <= st.size(); ++i) {
		if (tolower(st[i]) == 'f') {
			position = i;
			++num;
			if (num == 2) {
				break;
			}
		}
	}
	if (num == 2) {
		cout << position;

	} else if (num == 1) {
		cout << -1;

	} else {
		cout << -2;
	}

	return 0;
}
