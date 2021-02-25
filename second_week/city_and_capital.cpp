#include <iostream>
#include<map>
#include<vector>
using namespace std;

void Print(const map<string, string>& country_capital) {

	for (const auto& [key, value] : country_capital) {
		cout << key << '/' << value << " ";
	}
}


int main() {
	map<string, string> country_capital;

	size_t Q;
	cin >> Q;

	for (size_t i = 0; i < Q; ++i) {
		string operation_command;
		cin >> operation_command;

		if (operation_command == "CHANGE_CAPITAL") {

			string country, new_capital;
			cin >> country >> new_capital;

			if (!country_capital.count(country)) {

				cout << "Introduce new country " << country <<
						" with capital " << new_capital << endl;

				country_capital[country] = new_capital;

			} else  if (country_capital[country] == new_capital){

				cout << "Country " << country << " hasn't changed its capital" << endl;

			} else if (country_capital[country] != new_capital) {

				cout << "Country " << country << " has changed its capital from "
						<< country_capital[country] << " to " << new_capital << endl;

				country_capital[country] = new_capital;
			}

		} else if (operation_command == "RENAME") {

			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if (/*old_country_name == new_country_name ||*/
				!country_capital.count(old_country_name) ||
				country_capital.count(new_country_name)) {

				cout << "Incorrect rename, skip" << endl;

			} else {

				cout << "Country " << old_country_name << " with capital "
						<< country_capital[old_country_name]
						<< " has been renamed to " << new_country_name << endl;

				country_capital[new_country_name] = country_capital[old_country_name];
				country_capital.erase(old_country_name);
			}

		} else if (operation_command == "ABOUT") {

			string country;
			cin >> country;

			if (!country_capital.count(country)) {

				cout << "Country " << country << " doesn't exist" << endl;

			} else {

				cout << "Country " << country << " has capital "
						<< country_capital[country] << endl;
			}

		} else if (operation_command == "DUMP") {

			if (!country_capital.size()) {

				cout << "There are no countries in the world" << endl;

			} else {

				Print(country_capital);
			}

		}
	}

    return 0;
}
