#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Reverse(vector<int>& v) {
	int tmp;
	for(int i = 0; i < v.size() / 2; ++i) {
		tmp = v[i];
		v[i] = v[v.size() - i - 1];
		v[v.size() - i - 1] = tmp;
	}
}