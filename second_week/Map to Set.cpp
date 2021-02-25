#include<iostream>
#include<set>
#include<map>
#include<vector>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> receive;
	for (const auto& item : m) {
		receive.insert(item.second);
	}
	return receive;
}