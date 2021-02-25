#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(void){
	const string path = "input.txt";
	const string path1 = "output.txt";
	ifstream input(path);
	ofstream output(path1);

	if(output) {
		string line;
		while(getline(input, line)) {
			output << line << endl;
		}
	}
	return 0;
}
