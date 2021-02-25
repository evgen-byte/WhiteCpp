#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string BuildJoinedName(const string& first_name, const string& last_name) {

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

	if (s.empty()) {
		return "";
	}
	string name;

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

class Person {
public:
	Person(const string& first_name, const string& last_name, int year) {
		first_names[year] = first_name;
		last_names[year] = last_name;
	}
	string FindNameByYear(const map<int, string>& names, int year) const {
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
	bool IfYear(int year) const {
		vector<int> num;
		for (const auto& item : first_names){
			num.push_back(item.first);
			break;
		}
		if (year < num[0]) {
			return true;
		}
		return false;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (!IfYear(year)) {
			first_names[year] = first_name;
		}

	}
	void ChangeLastName(int year, const string& last_name) {
		if (!IfYear(year)) {
			last_names[year] = last_name;
		}
	}
	string GetFullName(int year) const {
		if (IfYear(year)) {
			return "No person";
		}
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		return BuildJoinedName(first_name, last_name);
	}
	string GetFullNameWithHistory(int year) const {
		if (IfYear(year)) {
			return "No person";
		}
		const string first_name = BuildName(GetHistoryName(first_names, year));
		const string last_name = BuildName(GetHistoryName(last_names, year));

		return BuildJoinedName(first_name, last_name);
	}

private:

	map<int, string> first_names;
	map<int, string> last_names;
};

int main() {

	Person person("Polina", "Sergeeva", 1960);
	  for (int year : {1959, 1960}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1965, "Appolinaria");
	  person.ChangeLastName(1967, "Ivanova");
	  for (int year : {1965, 1967}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	return 0;
}
