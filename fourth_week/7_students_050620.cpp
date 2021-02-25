#include<iostream>
//#include<ifstream> // для чтения(наследник istream)
//#include<ofstream> // для записи(наследник ostream)
#include<fstream>	 // для чтения и записи(наследник iostream)
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>

using namespace std;

struct Student {
	string firstname;
	string lastname;
	int day;
	int month;
	int year;
};

int main() {

	int n = 0;
	cin >> n;
	vector<Student> students(n);

	for (auto& student : students) {

		cin >> student.firstname >> student.lastname >>
			student.day >> student.month >> student.year;
	}

	int m = 0;
	cin >> m;

	if (m <= 10000) {

		for (int i = 1; i <= m; ++i) {

			string request;
			int student_num;
			cin >> request >> student_num;

			if (request == "name" && student_num <= students.size() && student_num > 0) {
				--student_num;
				cout << students[student_num].firstname << ' ' <<
						students[student_num].lastname << endl;

			} else if (request == "date" && student_num <= students.size() && student_num > 0) {
				--student_num;
				cout << students[student_num].day << '.' <<
						students[student_num].month << '.' <<
						students[student_num].year << endl;
			} else {
				cout << "bad request" << endl;
			}
		}
	}

	return 0;
}

