#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main(void){
	int q;
	cin >> q;

	map<vector<string>, int> buses;

	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<string> stops(n);
		for (string& stop : stops) {
			cin >> stop;
		}
		// ���������, �� ���������� �� ��� ������� � ����� ������� ���������
		if (buses.count(stops) == 0) {

			// ���� �� ����������, ����� ��������� ����� �������;
			// ��� ����� �� ������� ������ �������� ���������� ���������
			const int new_number = buses.size() + 1;
			buses[stops] = new_number;
			cout << "New bus " << new_number << endl;

		} else {
			cout << "Alrealy exists for " << buses[stops] << endl;
		}
	}
	return 0;
}
