#include<iostream>
#include<algorithm>
#include<sstream>
#include<system_error>
#include<exception>

using namespace std;

string AskTimeServer() {
	if (false) {
		throw system_error();
	}
	throw runtime_error("unexpected");
	return "01:28:55";
}

class TimeServer {
public:
	string GetCurrentTime() {
			try {
			last_fetched_time = AskTimeServer();
		} catch (const system_error&) {
		}
	 return last_fetched_time;
	}
private:
	string last_fetched_time = "00:00:00";
};

int main(){
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	} catch(exception& ex) {
		cout << "Exception got: " << ex.what() << endl;
	}

	return 0;
}
