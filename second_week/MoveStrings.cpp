#include<iostream>
#include<string>
#include<vector>
using namespace std;

void MoveStrings(vector<string>& src, vector<string>& dest) {
	for(auto s : src) {
		dest.push_back(s);
	}
	src.clear();
}
