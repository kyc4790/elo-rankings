#include "elo2.h"

#include <memory.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream f("rank.in");
	int N, subject;
	f >> N; //N is the number of people in the ranking system total
	cout << N << endl;
	f >> subject;
	cout << subject;
	if(subject) {
		return 0; //will be implemented when necessary
	}
	ELOMatch sys;
	for(int k =0; k < N; k++) { //reads in data
		string name;
		float ranking;
		int score;
		f >> name;
		f >> ranking;
		f >> score;
		
		sys.addPlayer(name, score, ranking);
	}
	cout << N;
	ofstream out("rank.out");

	sys.calculateELOs();
	cout << sys.players[0].eloChange << endl;
	for(int k = 0; k < N; k++) { //outputs data
		out << sys.players[k].name << "\t\t\t" << sys.players[k].eloPost << " " << "(";
		if(sys.players[k].eloChange > 0) {
			out << "+";
		}
		out << sys.players[k].eloChange <<")" << endl;
	}
}

