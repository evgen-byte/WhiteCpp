#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


int main(){
	ifstream input("input.txt");
	int line = 0;
	int column = 0;

	input >> line;
	input.ignore(1);
	input >> column;

	int num = 0;
	int l = 1;
	int c = 0;
	cout << right;

	while(input >> num) {
		++c;
		cout  << setw(10) << num;
		input.ignore(1);
		if (c == column && l < line) {
			cout << endl;
			++l;
		}
		if (c < column) {
			cout << ' ';
		} else {
			c = 0;
		}
	}
	return 0;
}
