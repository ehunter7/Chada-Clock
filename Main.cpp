#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

void HandleUserInput(int userInput, int& hours, int& minutes, int& seconds);
void DisplayMenu();
void SetTime(int& hours, int& minutes, int& seconds);
void DisplayClock(const int hours, const int minutes, const int seconds);

int main() {
	int hours, minutes, seconds;

	//UserInput defualt set to update time
	int userInput = 4;


	while (userInput != 5) {

	HandleUserInput(userInput, hours, minutes, seconds);

	DisplayClock(hours, minutes, seconds);

	cout << endl;

	DisplayMenu();

	cout << endl;

	cin >> userInput;

	system("clear");

	}



	return 0;
}

void HandleUserInput(int userInput, int& hours, int& minutes, int& seconds) {

		switch (userInput) {

		case 1:
			(hours != 24 ? hours++ : hours = 0);
			break;

		case 2:
			if (minutes != 59) {
				minutes++;
			}
			else {
				minutes = 0;
				(hours != 24 ? hours++ : hours = 0);
			}
			break;

		case 3:
			if (seconds != 59) {
				seconds++;
			}
			else {
				seconds = 0;
				(minutes != 59 ? minutes++ : minutes = 0);
			}

			break;

		case 4:
			SetTime(hours, minutes, seconds);
			break;

		default:
			break;
		}
}

void DisplayMenu() {

	char asterisk = '*';
	vector<string> menuItems = { "Hour", "Minute", "Second" };

	cout << setfill(asterisk) << setw(37) << asterisk << endl;
	
	for (int i = 0; i <= menuItems.size(); i++) {
		if (i != menuItems.size()) {

		cout  << asterisk << " " << i + 1 << " - Add One " << menuItems[i] << setfill(' ') 
			<< setw((i == 0 ? 19 : 17)) << asterisk << endl;
		}
		else {
			cout << asterisk << " " << i + 1 << " - Update Time" << setfill(' ') << setw(20) << asterisk << endl;
			cout << asterisk << " " << i + 2 << " - Exit" << setfill(' ') << setw(27) << asterisk << endl;
		}

	}

	cout << setfill(asterisk) << setw(37) << asterisk << endl;
}

void SetTime(int& hours, int& minutes, int& seconds) {
	struct tm newtime;
	//char am_pm[] = "AM";
	__time64_t long_time;
	//char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);


	hours = newtime.tm_hour;
	minutes = newtime.tm_min;
	seconds = newtime.tm_sec;

}

void DisplayClock(const int hours, const int minutes, const int seconds) {

	char asterisk = '*';

	string amPm;

	if (hours < 12 || hours == 24) {
		amPm = " AM";
	}
	else {
		amPm = " PM";
	}

	//Top border of clock
	cout << setfill(asterisk) << setw(26) << asterisk << " " << setw(26) << asterisk <<  endl;


	cout << asterisk << setfill(' ') <<  setw(18) << "12-Hour Clock" << setw(7) << setfill(' ') 
		<< asterisk << " " << asterisk << setw(19) << setfill(' ') << "24-Hour Clock" << setfill(' ') 
		<< setw(6) << asterisk << endl;

	 
	cout << asterisk << setfill(' ') << setw(6) << " ";

	//12 hour time
	cout << setfill('0') << setw(2) << (hours > 12 ? hours - 12 : hours) << ":" << setfill('0')
		<< setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << amPm;

	//sets space inbetween times
	cout << setw(8) << setfill(' ') << asterisk << " " << asterisk << setw(8) << setfill(' ') << " ";
	//24 hour time
	cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" <<
		setfill('0') << setw(2) << seconds << setfill(' ') << setw(9) << asterisk << endl;

	//bottom border of clock
	cout << setfill(asterisk) << setw(26) << asterisk << " " << setw(26) << asterisk << endl;
}



