/*
*Student Name: Jay Fisher
*File Name: Ch08Exercise07.cpp
*Date: 04/24/2025
*Visual C++ 2022   00476 - 80000 - 00000 - AA685
*Microsoft Visual C++ 2022
*/

#include <iostream> 
#include <conio.h>
#include <string>

using namespace std;

//  ------------------------------------------------------------------------
//  Program that  
//  ------------------------------------------------------------------------

//  Function to get percentage of votes
void Vote_Calc(double voter_list[], double percentage_list[]) {
	double total_votes = 0;
	for (int i = 0; i < 5; i++) {
		total_votes = total_votes + voter_list[i];
	}
	for (int i = 0; i < 5; i++) {
		percentage_list[i] = (voter_list[i] / total_votes) * 100;
	}
}

//  Function that finds the winner
void Winner(string names[], double sorting_list[], double percent[]) {
	bool found = false;
	int a, b, index_memory;
	double winning_vote, high_percent;
	string winner;
	for (a = 0; a < 4; a++) {
		winning_vote = sorting_list[a];
		winner = names[a];
		high_percent = percent[a];
		for (b = a + 1; b < 5; b++) {
			if (sorting_list[b] > winning_vote) {
				winner = names[b];
				winning_vote = sorting_list[b];
				high_percent = percent[b];
				index_memory = b;
				found = true;
			}
		}
		if (found == true) {
			sorting_list[index_memory] = sorting_list[a];
			sorting_list[a] = winning_vote;
			names[index_memory] = names[a];
			names[a] = winner;
			percent[index_memory] = percent[a];
			percent[a] = high_percent;
			found = false;
		}
	}
}

//  Main program
int main() {
	
	//  Declare variables
	double percentage[5], votes[5];
	int i = 0;
	int total_votes = 0;
	string people[5];
	string voter_suffix;
	
	//  Welcome screen and user input
	cout << "\n\n  Welcome to the calcomatic voting machine.";
	cout << "\n  I will talley the votes and see who won.";
	cout << "\n  ----------------------------------------" << endl; 
	do {
		if (i == 0) {
			voter_suffix = "st";
		}
		else if (i == 1) {
			voter_suffix = "nd";
		}
		else if (i == 2) {
			voter_suffix = "rd";
		}
		else {
			voter_suffix = "th";
		}
		cout << "\n  Please enter the " << i + 1 << voter_suffix << " voter's name : ";
		while (true) {
			if (cin >> people[i]) {
				break;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
			}
	
		}
		cout << "  Please enter the votes " << people[i] << " recevied : ";
		while (true) {
			if (cin >> votes[i]) {
				break;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	i++;
	}while (i < 5);
	Vote_Calc(votes, percentage);
	Winner(people, votes, percentage);
	cout << "\n\n  The voting result for this years election are...";
	cout << "\n  ------------------------------------------------" << endl;
	printf("  %-15s %-15s %-15s\n", "Name", "Votes", "Percentage");
	printf("  ------------------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		printf("  %-15s %-15.0f %-15.2f\n", people[i].c_str(), votes[i], percentage[i]);
	}
	total_votes = votes[0] + votes[1] + votes[2] + votes[3] + votes[4];
	printf("\n  Total votes: %-15d\n", total_votes);
	if (votes[0] == votes[1]) {
		cout << "\n\n  There is a tie, we may have to flip a coin.";
	}
	else {
		cout << "\n\n  The winner is " << people[0] << " with a whopping " << votes[0] << " votes.";
	}
	cout << "\n\n  Press any key to exit..."; 
	(void)_getch();
	return 0;
}