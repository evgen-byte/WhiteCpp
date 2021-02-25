#include<iostream>
#include<sstream>
#include<string>
#include<exception>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		string er = left + " != " + right;
		throw runtime_error(er);
	}
}

int main(void){
	try {
		EnsureEqual("C++ White", "C++ White");
		EnsureEqual("C++ White", "C++ Yellow");
	} catch (runtime_error& er) {
		cout << er.what() << endl;
	}

	return 0;
}
