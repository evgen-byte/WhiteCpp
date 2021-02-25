#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Students {
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
	Students(const string& f_name, const string& l_name, int d, int m, int y) {
		first_name = f_name;
		last_name = l_name;
		day = d;
		month = m;
		year = y;
	}
};
bool Limit(const string& f_name, const string& l_name, int d, int m, int y) {
	if (f_name.size() >= 1 && f_name.size() <= 15 &&
		l_name.size() >= 1 && l_name.size() <= 15 &&
		d >= 0 && d <= 1000000000 &&
		m >= 0 && d <= 1000000000 &&
		y >= 0 && y <= 1000000000) {
		return true;
	}
	return false;
}

int main(){
	vector<Students> student;

	int q_in;
	cin >> q_in;

	if (q_in >= 0 && q_in < 10000) {
		for (int i = 0; i < q_in; ++i) {
		string first_name;
		string last_name;
		int day;
		int month;
		int year;

		cin >> first_name >> last_name;
		cin >> day >> month >> year;
		if (Limit(first_name, last_name, day, month, year)) {
			student.push_back({first_name, last_name, day, month, year});
		}
	}
	}

	int q_out;
	cin >> q_out;

	if (q_out >= 0 && q_out < 10000) {
		for(int i = 0; i < q_out; ++i) {
		string request;
		int n;
		cin >> request >> n;

			if (student.size() == 0 || n > student.size() ||
					n < 1 || n > 10000 ||
					(request != "name" && request != "date")) {
				cout << "bad request" << endl;
			}
			else if (request == "name") {
			cout << student[n-1].first_name << ' ' << student[n-1].last_name << endl;

		} else if (request == "date") {
			cout << student[n-1].day << '.'
				<< student[n-1].month << '.'
				<< student[n-1].year << endl;
		}
	}
	}

	return 0;
}
