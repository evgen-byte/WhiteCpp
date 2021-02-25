#include<iostream>
#include<set>
#include<map>
#include<vector>

using namespace std;

int main() {
	int q;
	cin >> q;
	map<string, set<string>> synonyms;

	for (int i = 0; i < q; ++i) {

		string operation_code;
		cin >> operation_code;

		if (operation_code == "ADD") {

			string str_1, str_2;
			cin >> str_1 >> str_2;
			synonyms[str_1].insert(str_2);
			synonyms[str_2].insert(str_1);
		}
		else if (operation_code == "COUNT") {

			string word;
			cin >> word;
			cout << synonyms[word].size() << endl;
		}
		else if (operation_code == "CHECK") {

			string word_1, word_2;
			cin >> word_1 >> word_2;
			if (synonyms.count(word_1) == 1 && synonyms[word_1].count(word_2) == 1) {

				cout << "YES" << endl;
			} else {

				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
