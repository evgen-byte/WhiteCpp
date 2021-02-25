#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<int> months_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int month = 0;
	vector<vector<string>> deals(months_lengths[month]);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "ADD") {
			int day;
			string task;
			cin >> day >> task;
			--day;
			deals[day].push_back(task);
		}
		else if (operation_code == "DUMP") {
			int day;
			cin >> day;
			--day;
			cout << deals[day].size() << " ";
			for (const string& goal : deals[day]) {
				cout << goal << " ";
			}
			cout << endl;
		}
		else if (operation_code == "NEXT") {
			const int old_month = months_lengths[month];

			month = (month + 1) % months_lengths.size();
			const int new_month = months_lengths[month];

			if(new_month < old_month) {

				vector<string>& last_day = deals[new_month - 1];

				for(int day = new_month; day < old_month; ++day) {
					last_day.insert(end(last_day), begin(deals[day]), end(deals[day]));
				}
			}
			deals.resize(new_month);
		}
	}
	return 0;
}
