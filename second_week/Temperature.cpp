#include<iostream>
#include<vector>
using namespace std;

vector<int> DayTemp(const vector<int>& n, int& aver) {
	vector<int> temp_i;
	for(int i = 0; i < n.size(); ++i) {
		if(n[i] > aver) {
			temp_i.push_back(i);
		}
	}
	return temp_i;
}
int main() {
	int num_days;
	cin >> num_days;
	int average = 0;

	vector<int> temp(num_days);
	vector<int> res;

	for(int& t : temp) {
		cin >> t;
		average += t;
	}
	average /= num_days;
	res = DayTemp(temp, average);

	cout << res.size() << endl;
	for(auto t : res) {
		cout << t << " ";
	}
	return 0;
}
