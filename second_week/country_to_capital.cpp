#include<iostream>
#include<map>
#include<string>

using namespace std;

void PrintMap(const map<string, string>& country) {
	for(const auto& item : country) {
		cout << item.first << "/" << item.second << " ";
	}
	cout << endl;
}


int main() {
	map<string, string> country_capital;

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "CHANGE_CAPITAL") {
			string country, capital;//разлокалить
			cin >> country >> capital;

				if (!country_capital.count(country)) {
					cout << "Introduce new country " << country <<
							" with capital " << capital << endl;
					country_capital[country] = capital;
				}
				else if (country_capital[country] == capital) {
					cout << "Country " << country <<
							" hasn't changed its capital " << endl;
				}
				else if (country_capital[country] != capital){
					cout << "Country " << country << " has changed its capital from " <<
							country_capital[country] << " to " << capital << endl;
					country_capital[country] = capital;
				}
		}
		else if (operation_code == "RENAME") {
			string old_country, new_country;//разлокалить
			cin >> old_country >> new_country;
			if (country_capital.count(new_country) || !country_capital.count(old_country)) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				string temp_capital = country_capital[old_country];
				country_capital.erase(old_country);
				country_capital[new_country] = temp_capital;
				cout << "Country " << old_country << " with capital " <<
						temp_capital << " has been renamed to " <<
						new_country << endl;
			}
		}
		else if(operation_code == "ABOUT") {
			string country;
			cin >> country;
			if (!country_capital.count(country)) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital "
						<< country_capital[country] << endl;
			}
		}
		else if(operation_code == "DUMP") {
			if (!country_capital.size()) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				PrintMap(country_capital);
			}
		}
	}
	return 0;
}
