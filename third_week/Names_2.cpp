#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string FindNameByYear(map<int, string>& names, int year) {
	string name;

	for (const auto& item : names) {

		if (item.first <= year) {
			name = item.second;
		} else {
			break;
		}
	}
	return name;
}

vector<string> GetHistoryName(const map<int, string>& names, int year) {

	vector<string> history_name;
	string prev = "";

	for(const auto& item : names) {

		if (item.first <= year) {
			if (prev != item.second) {
				history_name.push_back(item.second);
			}
			prev = item.second;
		} else {
			break;
		}
	}
	reverse(begin(history_name), end(history_name));

	return history_name;
}
string BuildName(const vector<string>& s) {

	string name;

	if (!s.empty()) {

		if (s.size() == 1) {
			name = s[0];
		} else {
			name = s[0];
			name += " (";
			for (int i = 1; i < s.size() - 1; ++i) {
				name += s[i] + "," + " ";
			}
			name += s.back() + ")";
		}
	return name;
	}
	return "";
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		string first_name = FindNameByYear(first_names, year);
		string last_name = FindNameByYear(last_names, year);

		if (first_name.empty() && last_name.empty()) {

			return "Incognito";

		} else if (first_name.empty()) {

			return last_name + " with unknown first name";

		} else if (last_name.empty()) {

			return first_name + " with unknown last name";

		} else {

			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) {
		string first_name = BuildName(GetHistoryName(first_names, year));
		string last_name = BuildName(GetHistoryName(last_names, year));

		if (first_name.empty() && last_name.empty()) {

			return "Incognito";

		} else if (first_name.empty()) {

			return last_name + " with unknown first name";

		} else if (last_name.empty()) {

			return first_name + " with unknown last name";
		} else {

			return first_name + " " + last_name;
		}
		return "";
	}

private:

	map<int, string> first_names;
	map<int, string> last_names;
};

int main() {

	Person person;

	 person.ChangeFirstName(1965, "Polina");
	  person.ChangeLastName(1967, "Sergeeva");
	  for (int year : {1900, 1965, 1990}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1970, "Appolinaria");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeLastName(1968, "Volkova");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1990, "Polina");
	  person.ChangeLastName(1990, "Volkova-Sergeeva");
	  cout << person.GetFullNameWithHistory(1990) << endl;

	  person.ChangeFirstName(1966, "Pauline");
	  cout << person.GetFullNameWithHistory(1966) << endl;

	  person.ChangeLastName(1960, "Sergeeva");
	  for (int year : {1960, 1967}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeLastName(1961, "Ivanova");
	  cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
