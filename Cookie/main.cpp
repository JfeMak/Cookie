#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main(){
	int cookies {0};
	int totalCookies {0};
	int bakecount {0};
	int randomNum {};
	int multiplier {1};
	int upgradeCost {100};
	bool originalName {true};
	int randomChibbie {};
	int chibbieEncounters {0};
	bool onLeaderboard {false};
	
	string username;
	string command;
	
	vector <string> topPlayers {"w0VeryC0ol", "FatManJJJJ", "YumiBenkei", "BigChibbie", "DoritoPwev", 
		"qwerty12345", "BigFatFatt", "1234567890", "BlobbyMan!", "SmellyTwevi"};
	vector <int> topTotalCookies {14371437, 369369, 77777, 33333, 7777,
		6666, 3693, 3333, 2984, 777};
	vector <int> topBakeCount {14371, 9639, 7777, 6393, 777,
		636, 396, 369, 309, 82};
	vector <string> BakeListAchievements
		{"Baker",
		"Experienced Baker",
		"Professional Baker",
		"Challenger Baker",
		"Champion Baker"};
	vector <int> BakeAchievementDescriptions
		{10,
		25,
		50,
		100,
		200};
	vector <bool> BakeFinishedAchievements (BakeListAchievements.size(), false);
	vector <int> BakeAchievementRewards
		{50,
		250,
		500,
		750,
		1500};
	vector <string> ChibbieListAchievements
		{"Bebi Chibbie",
		"Chibbie",
		"Robo Chibbie",
		"Chibbie da Robo",
		"Chibbie da Robo, Robo da Chibbie"};
	vector <int> ChibbieAchievementDescriptions 
		{1,
		3,
		9,
		27,
		81};
	vector <bool> ChibbieFinishedAchievements (ChibbieListAchievements.size(), false);
	vector <int> ChibbieAchievementRewards
		{333,
		666,
		999,
		3333,
		10759};
	vector <string> CookieListAchievements
		{"Cookie Enthusiast",
		"Cookie Adorer",
		"Cookie Lover",
		"Cookie Fanatic",
		"Cookie Addict"};
	vector <int> CookieAchievementDescriptions
		{100,
		250,
		750,
		1500,
		3000};
	vector <bool> CookieFinishedAchievements (CookieListAchievements.size(), false);
	vector <int> CookieAchievementRewards
		{25,
		50,
		100,
		250,
		500};
	
	cout << "=================================" << endl;
	cout << "Welcome to Cookie Baker v1.7!" << endl;
	cout << "=================================" << endl;
	
	do {
		originalName = true;
		cout << "Enter your username (Must be 10 characters!): ";
		getline(cin, username);
		for (auto x : topPlayers) {
			if (username == x) {
				originalName = false;
			}
		}
		
		if (!originalName) {
			cout << "Please enter an original username" << endl;
		}
		if (username.length() != 10) {
			cout << "Make sure your username is at exactly 10 characters" << endl;
		}
		cout << endl;
	} while (username.length() != 10 || originalName == false);
	
	cout << "\nThanks for registering, " << username << "! \nStart by using ~help to get the list of all commands\n" << endl;
	
	do {
		cin >> command;
		
		// Commands
		
		if (command == "~help") {
			cout << "\nCommands:\n========\n" << endl;
			cout << "~b - Bakes some cookies :D (Random num from 1-5 * multiplier)" << endl;
			cout << "~i - Your profile with your stats 'n stuff 'u'" << endl;
			cout << "~u - Upgrades your oven! c: (Multiplies your multiplier by 2)" << endl;
			cout << "~lb - See all of the top bakers! :O" << endl;
			cout << "~changelog - Look at the recent and past changes :v" << endl;
			cout << "~chibbie - Generates a chibbie of random length ( ' )-( ' )" << endl;
			cout << "~a - A list of all possible achievements :]" << endl;
			cout << "~help - Brings you to this page :)" << endl;
			cout << "~exit - The command you use when you're full of yumi cookies :3 (Leaves the game)" << endl;
			cout << endl;
		} else if (command == "~b") {
			randomNum = (rand() % 5 + 1) * multiplier;
			cout << "\nYou baked " << randomNum << " cookies.\n" << endl;
			cookies = cookies + randomNum;
			totalCookies += randomNum;
			bakecount = bakecount + 1;
		} else if (command == "~i") {
			cout << endl;
			cout << username << "'s profile:" << endl;
			cout << "\n\nTotal # Cookies: " << totalCookies << endl;
			cout << "Current # of Cookies: " << cookies << endl;
			cout << "Total # of Bakes: " << bakecount << endl;
			cout << "Multiplier: " << multiplier << "x" << endl;
			cout << endl;
		} else if (command == "~u") {
			if (cookies >= upgradeCost) {
				cookies -= upgradeCost;
				multiplier *= 2;
				upgradeCost *= 4;
				cout << "\nYou upgraded your oven! Your multiplier is now " << multiplier << "x\n" << endl;
			} else {
				cout << "\nSorry, you don't have enough cookies. \nYou need " << (upgradeCost - cookies) << " more to upgrade.\n" << endl;
			}
		} else if (command == "~lb") {
			cout << "\nTop 10 (All Time)\n=================\n" << endl;
			for (int i = 0; i < 10; i ++) {
				if (totalCookies > topTotalCookies.at(i) && !onLeaderboard) {
					cout << (i + 1) << ". " << username << endl;
					cout << "\tTotal Cookies: " << totalCookies << endl;
					cout << "\tBake Count: " << bakecount << endl;
					onLeaderboard = true;
					i++;
				}
				if (i == 10) {
					break;
				}
				if (onLeaderboard) {
					cout << (i + 1) << ". " << topPlayers.at(i - 1) << endl;
					cout << "\tTotal Cookies: " << topTotalCookies.at(i - 1) << endl;
					cout << "\tBake Count: " << topBakeCount.at(i - 1) << endl;
				} else {
					cout << (i + 1) << ". " << topPlayers.at(i) << endl;
					cout << "\tTotal Cookies: " << topTotalCookies.at(i) << endl;
					cout << "\tBake Count: " << topBakeCount.at(i) << endl;
				}
			}
			cout << endl;
		} else if (command == "~changelog") {
			cout << "\nChangelog\n=========\n" << endl;
			cout << "0.0 - Game created (Basic baking)" << endl;
			cout << "0.1 - Added ~i command" << endl;
			cout << "0.2 - Made the cookies gained from ~b random" << endl;
			cout << "0.3 - Added upgrade & multipliers" << endl;
			cout << "0.4 - Fixed some formatting stuff" << endl;
			cout << "0.5 - Added ~help command" << endl;
			cout << "0.6 - Added ~changelog command" << endl;
			cout << "0.7 - Added ~lb command" << endl;
			cout << "0.8 - Added the total # of cookies that you baked in a lifetime" << endl;
			cout << "0.9 - Added names of top players and 10-character-check for username" << endl;
			cout << "0.10 - Added the username taken check" << endl;
			cout << "1.0 - Working leaderboard & fixed some formatting errors" << endl;
			cout << "1.1 - Added ~chibbie command & fixed some formatting errors" << endl;
			cout << "1.2 - Chibbie Da ROBOOOOOO :D & increased max chibbie size from 20 to 30" << endl;
			cout << "1.3 - Basic Achievements" << endl;
			cout << "1.4 - Made leaderboard more reasonable & fixed double achievement message error" << endl;
			cout << "1.5 - Fixed leaderboard out of range error" << endl;
			cout << "1.6 - Added chibbie achievements & fixed leaderboard bad_alloc error" << endl;
			cout << "1.7 - Added cookie achievements & simplified the code for the achievements command (~a)" << endl;
			cout << endl;
		} else if (command == "~chibbie") {
			randomChibbie = rand() % 30 + 1;
			cout << "( ' )";
			for (int i = 0; i < randomChibbie; i++) {
				cout << "-";
			}
			cout << "( ' )";
			if (randomChibbie == 30) {
				cout << "Chibbie Da ROBO, ROBO Da Chibbie!" << endl;
				chibbieEncounters++;
			}
			cout << endl;
		} else if (command == "~a") {
			cout << endl;
			for (int i = 0; i < BakeListAchievements.size(); i++) {
				cout << ( i + 1 ) << ". " << BakeListAchievements.at(i) << endl;
				cout << "\t- Bake " << BakeAchievementDescriptions.at(i) << " times" << endl;
				cout << "\t- ";
				if (BakeFinishedAchievements.at(i)) {
					cout << "Completed!" << endl;
				} else {
					cout << "Not Completed (" << bakecount << " / " << BakeAchievementDescriptions.at(i) << ")" << endl;
				}
			}
			for (int i = 0; i < ChibbieListAchievements.size(); i++) {
				cout << (i + 1 + BakeListAchievements.size()) << ". " << ChibbieListAchievements.at(i) << endl;
				cout << "\t-Encounter Chibbie Da Robo, Robo Da Chibbie " << ChibbieAchievementDescriptions.at(i) << " times." << endl;
				cout << "\t-";
				if (ChibbieFinishedAchievements.at(i)) {
					cout << "Completed!" << endl;
				} else {
					cout << "Not Completed (" << chibbieEncounters << " / " << ChibbieAchievementDescriptions.at(i) << ")" << endl;
				}
			}
			for (int i = 0; i < CookieListAchievements.size(); i++) {
				cout << (i + 1 + BakeListAchievements.size() + ChibbieListAchievements.size()) << ". " << CookieListAchievements.at(i) << endl;
				cout << "\t-Bake " << CookieAchievementDescriptions.at(i) << " cookies in total." << endl;
				cout << "\t-";
				if (CookieFinishedAchievements.at(i)) {
					cout << "Completed!" << endl;
				} else {
					cout << "Not Completed (" << totalCookies << " / " << CookieAchievementDescriptions.at(i) << ")" << endl;
				}
			}
			
			
			cout << endl;
		}
		
		// Checking if a baking achievement is complete
		
		for (int i = 0; i < BakeListAchievements.size(); i++) {
			if (bakecount == BakeAchievementDescriptions.at(i) && !BakeFinishedAchievements.at(i)) {
				cout << endl;
				cout << "You finished achievement: " << BakeListAchievements.at(i) << endl;
				cout << "You get " << BakeAchievementRewards.at(i) << " cookies as a reward! :D" << endl;
				cout << "Check your progress on achievements with ~a" << endl;
				cookies += BakeAchievementRewards.at(i);
				totalCookies += BakeAchievementRewards.at(i);
				BakeFinishedAchievements.at(i) = true;
				cout << endl;
			}
		}
		
		// Checking if a chibbie achievement is complete
		
		for (int i = 0; i < ChibbieListAchievements.size(); i++) {
			if (chibbieEncounters == ChibbieAchievementDescriptions.at(i) && !ChibbieFinishedAchievements.at(i)) {
				cout << endl;
				cout << "You finished achievement: " << ChibbieListAchievements.at(i) << endl;
				cout << "You get " << ChibbieAchievementRewards.at(i) << " cookies as a reward! ( ' )-( ' )" << endl;
				cout << "Check your progress on achievements with ~a" << endl;
				cookies += ChibbieAchievementRewards.at(i);
				totalCookies += ChibbieAchievementRewards.at(i);
				ChibbieFinishedAchievements.at(i) = true;
			}
		}
		
		// Checking if a cookie achievement is complete
		
		for (int i = 0; i < CookieListAchievements.size(0); i++) {
			if (totalCookies == CookieAchievementDescriptions.at(i) && !CookieFinishedAchievements.at(i)) {
				cout << endl;
				cout << "You finished achievement: " << CookieListAchievements.at(i) << endl;
				cout << "You get " << CookieAchievementRewards.at(i) << " cookies as a reward! :P" << endl;
				cout << "Check your progress on achievements with ~a" << endl;
				cookies += CookieAchievementRewards.at(i);
				totalCookies += CookieAchievementRewards.at(i);
				CookieFinishedAchievements.at(i) = true;
			}
		}
		
	} while (command != "~exit"); 
	
	return 0;
}