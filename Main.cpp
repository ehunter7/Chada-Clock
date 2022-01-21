#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

void DisplayMenu();
void DisplayClock();

int main() {

	int userInput;

	DisplayClock();

	DisplayMenu();

	cin >> userInput;



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
			cout << asterisk << " " << i + 1 << " - Exit" << asterisk <<  endl;
		}

	}

	cout << setfill(asterisk) << setw(37) << asterisk << endl;
}

void DisplayClock() {

	struct tm newtime;
	//char am_pm[] = "AM";
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);




	cout << newtime.tm_hour << endl;
	char asterisk = '*';
	cout << setfill(asterisk) << setw(26) << asterisk << endl;

	cout << "12-Hour Clock" << endl;
	cout << "The time will go here" << endl;

	cout << setfill(asterisk) << setw(26) << asterisk << endl;

}