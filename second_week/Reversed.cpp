#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> Reversed(const vector<int>& nums) {
	vector<int> invert;
	for(int i = nums.size() - 1; i >= 0; --i) {
		invert.push_back(nums[i]);
	}
	return invert;
}