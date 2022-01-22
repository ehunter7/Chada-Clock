#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

void DisplayMenu();
void SetTime(int& hours, int& minutes, int& seconds);
void DisplayClock(const int hours, const int minutes, const int seconds);

int main() {
	int hours, minutes, seconds;

	//UserInput defualt set to update time
	int userInput = 4;

	while (userInput != 5) {

	switch (userInput) {
	case 1:
		hours++;
		break;
	case 2:
		minutes++;
		break;
	case 3:
		seconds++;
		break;
	case 4: 
		SetTime(hours, minutes, seconds);
		break;
	default:
		break;
	}

	DisplayClock(hours, minutes, seconds);

	DisplayMenu();

	cin >> userInput;

	system("clear");

	}



	return 0;
}

void DisplayMenu() {

	char asterisk = '*';
	vector<string> menuItems = { "Hour", "Minute", "Second" };

	cout << setfill(asterisk) << setw(37) << asterisk << endl;
	
	for (int i = 0; i <= menuItems.size(); i++) {
		if (i != menuItems.size()) {

		cout  << asterisk << " " << i + 1 << " - Add One " << menuItems[i] << asterisk << endl;
		}
		else {
			cout << asterisk << " " << i + 1 << " - Update Time" << asterisk << endl;
			cout << asterisk << " " << i + 2 << " - Exit" << asterisk <<  endl;
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

	//Top border of clock
	cout << setfill(asterisk) << setw(26) << asterisk << " " << setw(26) << asterisk <<  endl;


	cout << "12-Hour Clock" << setw(27) << setfill(' ') <<  "24-Hour Clock" << endl;

	//12 hour time
	cout << setfill('0') << setw(2) << (hours > 12 ? hours - 12 : hours) << ":" << setfill('0') << setw(2) << minutes << ":" << 
		setfill('0') << setw(2) << seconds << (hours > 12 ? " PM" : " AM");

	//sets space inbetween times
	cout << setw(27) << setfill(' ') << " ";

	//24 hour time
	cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" <<
		setfill('0') << setw(2) << seconds << endl;

	//bottom border of clock
	cout << setfill(asterisk) << setw(26) << asterisk << " " << setw(26) << asterisk << endl;
}



