#include<iostream>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<exception>
#include<iomanip>
#include<vector>
using namespace std;

class Date {
public:
	Date () {
		year = 1;
		month = 1;
		day = 1;
	}
	Date(int new_year, int new_month, int new_day) {
		year = new_year;

		if (new_month < 1 || new_month > 12) {
			string error = "Month value is invalid: " + to_string(new_month);
			throw invalid_argument(error);
		}
		month = new_month;
		if (new_day < 1 || new_day > 31) {
			string error = "Day value is invalid: " + to_string(new_day);
			throw invalid_argument(error);
		}
		day = new_day;
	}

  int GetYear() const {
	  return year;
  }
  int GetMonth() const {
	  return month;
  }
  int GetDay() const {
	  return day;
  }

private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
			vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
ostream& operator << (ostream& stream, const Date& date) {
	stream << setfill('0');
	stream << setw(4) << date.GetYear() << '-' <<
			setw(2) << date.GetMonth() << '-' <<
			setw(2) << date.GetDay();
	return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
		  dtbs[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
	  if (dtbs.count(date) > 0) {
		 if (dtbs[date].count(event) > 0) {
			 dtbs[date].erase(event);
			 return true;
		 }
	  }
	  return false;
  }

  int  DeleteDate(const Date& date) {
	 int event = dtbs[date].size();
	 dtbs.erase(date);
	 return event;
  }


  set<string> Find(const Date& date) const {
	  set<string> events;
	  if (dtbs.count(date) > 0) {
		  events = dtbs.at(date);
	  }
	  return events;
  }


  void Print() const {
	  for (const auto& date : dtbs) {
		  for (const auto& event : date.second) {
			  cout << date.first << ' ' << event << endl;
		  }
	  }
  }
private:
  map<Date, set<string>> dtbs;
};

Date ParseDate(const string& s_date) {
	stringstream stream(s_date);

	int year, month, day;

	stream >> year;
	bool correct = stream && (stream.peek() == '-');
	stream.ignore(1);
	stream >> month;
	correct = stream && (stream.peek() == '-');
	stream.ignore(1);
	stream >> day;
	correct = stream && stream.eof();

	if (!correct) {
		string error = "Wrong date format: " + s_date;
		throw invalid_argument(error);
	}
	return {year, month, day};
}

int main() {

	try {
	Database db;

  string command;
  while (getline(cin, command)) {

    istringstream command_line(command);

    string operation_code;
    command_line >> operation_code;

    if (operation_code == "Add") {
    	string ymd;
    	string event;
    	command_line >> ymd >> event;

    	Date date = ParseDate(ymd);
    	db.AddEvent(date, event);

    } else if (operation_code == "Del") {
    	string data;
    	string event;
    	command_line >> data;
    	if (command_line.eof()) {
    		Date date = ParseDate(data);
    		int events = db.DeleteDate(date);
    		cout << "Deleted " << events << " events" << endl;
    	} else {
    		command_line >> event;
    		Date date = ParseDate(data);

    		if (db.DeleteEvent(date, event)) {
    			cout << "Deleted successfully" << endl;

    		} else {
    			cout << "Event not found" << endl;
    		}

    	}

    } else if (operation_code == "Find") {
    	string data;
    	set<string> events;
    	command_line >> data;
    	Date date = ParseDate(data);
    	events = db.Find(date);
    	if (!events.empty()) {
    		for (auto& event : events) {
    			cout << event << endl;
    		}
    	}

    } else if (operation_code == "Print") {
    	db.Print();

    } else if (command_line){
    	cout << "Unknown command: " + operation_code << endl;
    }
  }
	} catch (invalid_argument& inv) {
		cout << inv.what() << endl;
	}
	//  Ç   À   Å   Á   È   Ñ   Ü ! ! !

  return 0;
}
