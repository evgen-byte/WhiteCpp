#include<iostream>
#include<string>
using namespace std;

struct Specialization {
	string value;
	explicit Specialization(string new_value) {
		value = new_value;
	}
};
struct Course {
	string value;
	explicit Course(string new_value) {
		value = new_value;
	}
};
struct Week {
	string value;
	explicit Week(string new_value) {
		value = new_value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
};
void Print(const LectureTitle& lecture) {
	cout << lecture.specialization << endl << lecture.course
			<< endl << lecture.week << endl;
}
int main(){



	return 0;
}
