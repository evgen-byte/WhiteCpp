#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void Print(const vector<int>& i) {
	for (const auto& num : i) {
		cout << num << " ";
	}
	cout << endl;
}

bool Compar(int x, int y) {
	return (abs(x) < abs(y));
}
int main(){

	int n;
	cin >> n;
	vector<int> num(n);

	for (auto& i : num) {
		cin >> i;
	}
	sort(begin(num), end(num), Compar);
	// с использованием лямбды
	sort(begin(num), end(num),
	[](int x, int y){return (abs(x) < abs(y));}
  );
	
	Print(num);

	return 0;
}
