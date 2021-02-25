#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string FindNameByYear(map<int, string>& names, int year) {
	string name;

	for (const auto& item : names) {
		if(item.first <= year) {
			name = item.second;
		} else {
			break;
		}
	}
	return name;
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
		string first = FindNameByYear(first_names, year);
		string last = FindNameByYear(last_names, year);

		if (first.empty() && last.empty()) {

			return "Incognito";
		} else if (first.empty()) {

			return last + " with unknown first name";
		} else if (last.empty()) {

			return first + " with unknown last name";
		} else {
			return first + " " + last;
		}
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
	    cout << person.GetFullName(year) << endl;
	  }

	  person.ChangeFirstName(1970, "Appolinaria");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullName(year) << endl;
	  }

	  person.ChangeLastName(1968, "Volkova");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullName(year) << endl;
	  }


	return 0;
}
