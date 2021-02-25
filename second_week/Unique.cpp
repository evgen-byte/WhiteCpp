#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(void){
	/*int num_of_lines;
	cin >> num_of_lines;

	vector<string> stroka;
	stroka.resize(num_of_lines);

	for (string& string : stroka) {
		cin >> string;
	}
	set<string> uniq(begin(stroka), end(stroka));
	cout << uniq.size() << endl;*/

		int n;
		cin >> n;

		set<string> uniq;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
			uniq.insert(str);
		}
		cout << uniq.size() << endl;

	return 0;
}
