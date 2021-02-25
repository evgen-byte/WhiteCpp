#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

int main(void){
	ifstream input("input.txt");

	cout << fixed << setprecision(3);
	double num = 0;

	while(input >> num) {
		cout << num << endl;
	}

	return 0;
}
