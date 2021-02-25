#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<bool> queue(0, false);
	int n, q;
	string s;

	cin >> q;
	while(q > 0) {
		cin >> s;

		if(s == "COME") {
			cin >> n;
			if(n > 0) {
				queue.resize(queue.size() + n);
			}
			else if(n >= -queue.size() && queue.size()) {
				queue.resize(queue.size() + n);
			}
			--q;
		}
		else if(s == "WORRY") {
			cin >> n;
			if(n < queue.size() && n >= 0) {
				queue[n] = true;
			}
			--q;
		}
		else if(s == "QUIET") {
			cin >> n;
			if(n < queue.size() && n >= 0) {
				queue[n] = false;
			}
			--q;
		}
		else if(s == "WORRY_COUNT") {
							int i = 0;
							for(auto w : queue) {
								if(w == true) {
									++i;
								}
							}
							--q;
							cout << i << endl;
						}
	}
	return 0;
}