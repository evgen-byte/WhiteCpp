#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
	map<char, int> counters;
	for(char c : word) {
		++counters[c];
	}
	return counters;
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		string f_word, s_word;
		cin >> f_word >> s_word;
		if(BuildCharCounters(f_word) == BuildCharCounters(s_word)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
