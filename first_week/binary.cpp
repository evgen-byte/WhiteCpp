#include <iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> bin;

	while (n > 0) {
		bin.push_back(n % 2);
		n /= 2;
	}

	for (size_t i = bin.size(); i > 0; --i) {
		cout << bin[i-1];
	}

  return 0;
}
