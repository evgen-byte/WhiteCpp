#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){
	int q;
	cin >> q;

	map<vector<string>, int> nums_route;

	for (int i = 0; i < q; ++i) {

		int num_route;
		int stops_count;
		cin >> stops_count;
		vector<string> stops_name;
		stops_name.resize(stops_count);

		for (string& in_stops : stops_name) {
			cin >> in_stops;
		}

		if (nums_route.count(stops_name) == 0) {
			nums_route[stops_name];
			num_route = nums_route.size();
			nums_route[stops_name] = num_route;
			cout << "New bus " << nums_route[stops_name] << endl;
		} else {
			cout << "Already exists for " << nums_route[stops_name] << endl;
		}
		stops_name.clear();
	}
 	return 0;
}
