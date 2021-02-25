#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

void PrintMap(const map<string, vector<string>>& m) {
	for (const auto& item : m) {
			cout << "Bus " << item.first << ": ";
			for (const string& str : item.second) {
				cout << str << " ";
			}
			cout << endl;
		}
}
int main(){
	map<string, vector<string>> bus_and_stop;
	map<string, vector<string>> stop_to_bus;

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;
		if (operation_code == "NEW_BUS") {

			string bus;
			cin >> bus;

			int stop_count;
			cin >> stop_count;
			//считываем остановки в вектор строк
			vector<string> stop(stop_count);
			for (string& str : stop) {
				cin >> str;
			}
			if (!bus_and_stop.count(bus)) {
				//добавление маршрута в вектор
				for (const string& str : stop) {
			bus_and_stop[bus].push_back(str);
			stop_to_bus[str].push_back(bus);
		}
			}
		}
		else if (operation_code == "ALL_BUSES") {
			if (!bus_and_stop.size()) {
				cout << "No buses" << endl;
			}
			PrintMap(bus_and_stop);
		}

		else if (operation_code == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			if (stop_to_bus.count(stop)) {
				for (const auto& bus : stop_to_bus[stop]) {
					cout << bus << " ";
				}
			}
			if (!stop_to_bus.count(stop)) {
				cout << "No stop";
			}
			cout << endl;
		}
		else if (operation_code == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (!bus_and_stop.size() || !bus_and_stop.count(bus)) {
				cout << "No bus" << endl;
			}
			else if (bus_and_stop.count(bus)) {
				//проходим по ключам автобусов и считываем остановки в порядке добавления
				for (const string& item_stop : bus_and_stop[bus]){
					int i = 0;
					//проходим по ключам остановок и считываем маршруты в порядке добавления
					for(const string& item_bus : stop_to_bus[item_stop]) {
						if (item_bus != bus) {
							++i;
							if(i == 1) {
								cout << "Stop " << item_stop << ": ";
							}
							 cout << item_bus << " ";
						}
					}
					if (i == 0) {
						cout << "Stop " << item_stop << ": " << "no interchange";
					}
					cout << endl;
				}
			}
		}
	}
 	return 0;
}
