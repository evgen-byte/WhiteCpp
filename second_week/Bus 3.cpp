#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main() {
	int q;
	cin >> q;

	map<set<string>, int> rotes;

	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<string> stops(n);
		for (string& stop : stops) {
			cin >> stop;
		}
		// временное множество для вставки ключа в map
		set<string> temp;
		
		temp.insert(begin(stops), end(stops));
		// set<string> temp(begin(stops), end(stops));

		if (rotes.count(temp) == 0) {

			const int new_number = rotes.size() + 1;
			rotes[temp] = new_number;
			cout << "New bus" << " " << new_number << endl;
		} else {
			cout << "Already exists for" << " " << rotes[temp] << endl;
		}
	}
	return 0;
}
