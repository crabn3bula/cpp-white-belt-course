#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() {
        day_ = 0;
        month_ = 0;
        year_ = 0;
    }

    int GetYear() const {
        return year_;
    }

    int GetMonth() const {
        return month_;
    }

    int GetDay() const {
        return day_;
    }

    void SetDate(string& str) {
        ParseDate(str);
    }
    static const char delimiter = '-';
private:
    int day_;
    int month_;
    int year_;

    void ParseDate(string& str) {
        stringstream stream(str);
        int tmp_day, tmp_month, tmp_year;

        stream >> tmp_year;
        EnsureDelimiterAndSkip(stream, str);
        stream >> tmp_month;
        EnsureDelimiterAndSkip(stream, str);
        stream >> tmp_day;

        // characters after day
        if (!stream.eof() || stream.fail()) {
            throw runtime_error("Wrong date format: " + str);
        }

        ValidateMonth(tmp_month);
        ValidateDay(tmp_day);

        // date is valid
        day_ = tmp_day;
        month_ = tmp_month;
        year_ = tmp_year;
    }

    void ValidateMonth(int month) {
        if (month < 1 || month > 12) {
            throw runtime_error("Month value is invalid: " + to_string(month));
        }
    }

    void ValidateDay(int day) {
        if (day < 1 || day > 31) {
            throw runtime_error("Day value is invalid: " + to_string(day));
        }
    }

    void EnsureDelimiterAndSkip(stringstream& stream, string& date) {
        if (stream.peek() != Date::delimiter) {
            throw runtime_error("Wrong date format: " + date);
        }
        stream.ignore(1);
    }
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    }

    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) {
        return true;
    }

    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth()) {
        return lhs.GetDay() < rhs.GetDay();
    }

    return false;
}

istream& operator>>(istream& stream, Date& date) {
    string date_str;
    stream >> date_str;
    date.SetDate(date_str);
    return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0') << setw(4) << date.GetYear() << Date::delimiter;
    stream << setfill('0') << setw(2) << date.GetMonth() << Date::delimiter;
    stream << setfill('0') << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        records_[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        return records_[date].erase(event);
    }

    int DeleteDate(const Date& date) {
        const int events_count = records_[date].size();
        records_[date].clear();
        return events_count;
    }

    set<string> Find(const Date& date) const {
        if (records_.count(date) > 0) {
            return records_.at(date);
        }
        return {};
    }

    void Print() const {
        for (const auto& record: records_) {
            for (const auto& event : record.second) {
                cout << record.first << " " << event << endl;
            }
        }
    }
private:
    map<Date, set<string>> records_;
};

int main() {
    Database db;
    string command;
    
    try {
        while (getline(cin, command)) {
            string command_name;
            Date date;
            string evt;

            stringstream str(command);
            str >> command_name;

            if (command_name == "Add") {
                str >> date;
                str >> evt;

                db.AddEvent(date, evt);
            }
            else if (command_name == "Del") {
                str >> date;

                if (str >> evt) {
                    const auto is_deleted = db.DeleteEvent(date, evt);
                    cout << (is_deleted ? "Deleted successfully" : "Event not found") << endl;
                }
                else {
                    const auto cnt = db.DeleteDate(date);
                    cout << "Deleted " << cnt << " events" << endl;
                }
            }
            else if (command_name == "Find") {
                str >> date;
                auto events = db.Find(date);
                for (const auto& event : events) {
                    cout << event << endl;
                }
            }
            else if (command_name == "Print") {
                db.Print();
            }
            else if (command_name.empty())
            {
                // ignore
            }
            else {
                stringstream error_msg;
                error_msg << "Unknown command: " << command_name;
                throw runtime_error(error_msg.str());
            }
        }
    } catch (runtime_error& ex) {
        cout << ex.what() << endl;
        return 0;
    }
    
    return 0;
}