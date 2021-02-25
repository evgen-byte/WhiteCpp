#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void Print(const string& path) {
	ifstream input(path);
	if(input) {
		string line;
		while(getline(input, line)) {
			cout << line << endl;
		}
	} else {
		cout << "error" << endl;
	}
}

int main(void){
	string path = "input.txt";
	ifstream input(path);

	Print(path);

	return 0;
}
