// ##################################################
// File: Main.cpp
// Author: Eric Hunter
// Date: January 22, 2022
// Description: Contains all code for the Chada Clock assignment
// ##################################################

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//Function Declarations
void HandleUserInput(int userInput, int& hours, int& minutes, int& seconds);
void DisplayMenu();
void SetTime(int& hours, int& minutes, int& seconds);
void DisplayClock(const int hours, const int minutes, const int seconds);

int main() {

	//Declaring int variable to hold the time in hours minutes and seconds
	int hours, minutes, seconds;

	//UserInput defualt set to update time
	int userInput = 4;

	// While loop runs until exit option is chosen from menu
	// 5 is the exit line item on menu
	while (userInput != 5) {

	HandleUserInput(userInput, hours, minutes, seconds);

	DisplayClock(hours, minutes, seconds);

	// Extra line space for readability
	cout << endl;

	DisplayMenu();

	// Extra line space for readability
	cout << endl;

	//Get user input form keyboard
	cin >> userInput;

	//boolean used to validate user input
	bool validMenueOption = false;

	// Checks if user entered valid menu otion, if not display error and ask user to try again 
	while (!validMenueOption){

		try {

			if (userInput < 1 || userInput > 5) {

				throw exception("Invalid menu option.");
			}

			validMenueOption = true;
		}
		catch (const exception& error) {

			// Clear the failed attempt
			cin.clear(); 
			//tmp string used to help clear failed input attempt
			string tmp;
			// flush the stream
			getline(cin, tmp); 

			cout <<  error.what() << " Please try again:" << endl;

			// Get user Input
			cin >> userInput;
		}
	}

	// Clears the console to display updated clocks
	system("clear");
	}

	return 0;
}


// ################################################################
// @par Name
// HandleUserInput
// @purpose
// Takes in the users input and performs actions based on the input
// @param [in]:
// int userInput, int& hours, int& minutes, int& seconds
// @return
// void
// @par References
// none
// @par Notes
// Used to add time to clock or update clock based on the users input
// Switch case is based off of menu items.
// ################################################################
void HandleUserInput(int userInput, int& hours, int& minutes, int& seconds) {

		switch (userInput) {

		case 1:

			//If user adds an hour, check if hour is 24 indicating end of day.
			//If end of day restart hours back at zero
			(hours != 24 ? hours++ : hours = 0);

			break;

		case 2:
			//If end of hour reset minutes and add an hour
			if (minutes != 59) {

				minutes++;
			}
			else {

				minutes = 0;
				(hours != 24 ? hours++ : hours = 0);
			}
			break;

		case 3:

			//If end of minute, reset seconds and add a minute
			if (seconds != 59) {

				seconds++;
			}
			else {

				seconds = 0;

				if (minutes != 59) {

					minutes++;
				}
				else {

					minutes = 0;
					hours++;
				}
			}
			break;

		case 4:

			//Option 4 on menu to update the time
			SetTime(hours, minutes, seconds);

			break;

		default:
			break;
		}
}


// ################################################################
// @par Name
// DisplayMenu
// @purpose
// Formats and displays menu on the console
// @param [in]:
// none
// @return
// void
// @par References
// none
// @par Notes
// For loop iterates through menu items and displays them to the screen. 
// ################################################################
void DisplayMenu() {

	char asterisk = '*';

	vector<string> menuItems = { "Hour", "Minute", "Second" };

	// Top border of Menu
	cout << setfill(asterisk) << setw(37) << asterisk << endl;
	
	//For loop iterates through vector menue items to get each option. 
	for (int i = 0; i <= menuItems.size(); i++) {

		//If end of menuItems is not met pull from menu items
		if (i != menuItems.size()) {

		cout  << asterisk << " " << i + 1 << " - Add One " << menuItems[i] << setfill(' ') 
			<< setw((i == 0 ? 19 : 17)) << asterisk << endl;
		}
		//Otherwise add ending menu options
		else {
			cout << asterisk << " " << i + 1 << " - Update Time" << setfill(' ') << setw(20) << asterisk << endl;
			cout << asterisk << " " << i + 2 << " - Exit" << setfill(' ') << setw(27) << asterisk << endl;
		}
	}
	//Bottom border of menu
	cout << setfill(asterisk) << setw(37) << asterisk << endl;
}


// ################################################################
// @par Name
// SetTime
// @purpose
// Sets the variables passed in by reference to the current local time. 
// @param [in]:
// int& hours, int& minutes, int& seconds
// @return
// void
// @par References
// Microsoft docs
// @par Notes
// Used to get the local time. Set variable by reference.
// ################################################################
void SetTime(int& hours, int& minutes, int& seconds) {


	struct tm newtime;
	
	__time64_t long_time;
	
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);

	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);

	// Sets the hour, minute and second to current local time
	hours = newtime.tm_hour;
	minutes = newtime.tm_min;
	seconds = newtime.tm_sec;
}


// ################################################################
// @par Name
// DisplayClock
// @purpose
// Formats and displays the two clocks. 
// @param [in]:
// const int hours, const int minutes, const int seconds
// @return
// void
// @par References
// none
// @par Notes
// cout statement were getting long. Tried to break them up for readability.
// ################################################################
void DisplayClock(const int hours, const int minutes, const int seconds) {

	char asterisk = '*';
	char space = ' ';
	char colon = ':';

	string amPm;

	//Used to determine if its am or pm.
	if (hours < 12 || hours == 24) {
		amPm = " AM";
	}
	else {
		amPm = " PM";
	}

	//Top border of clock
	cout << setfill(asterisk) << setw(26) << asterisk << space << setw(26) << asterisk <<  endl;

	// clock labels that sit above the time
	cout << asterisk << setfill(space) <<  setw(18) << "12-Hour Clock" << setw(7) << setfill(space)
		<< asterisk << space << asterisk << setw(19) << setfill(space) << "24-Hour Clock" << setfill(space)
		<< setw(6) << asterisk << endl;

	// Sace inbetween 12 hour time and 24 hour time
	cout << asterisk << setfill(space) << setw(6) << space;

	//12 hour time
	cout << setfill('0') << setw(2) << (hours > 12 ? hours - 12 : hours) << colon << setfill('0')
		<< setw(2) << minutes << colon << setfill('0') << setw(2) << seconds << amPm;

	//sets space inbetween times
	cout << setw(8) << setfill(space) << asterisk << space << asterisk << setw(8) << setfill(space) << space;

	//24 hour time
	cout << setfill('0') << setw(2) << hours << colon << setfill('0') << setw(2) << minutes << colon <<
		setfill('0') << setw(2) << seconds << setfill(space) << setw(9) << asterisk << endl;

	//bottom border of clock
	cout << setfill(asterisk) << setw(26) << asterisk << space << setw(26) << asterisk << endl;
}





