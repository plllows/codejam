#include <bits/stdc++.h>
using namespace std;

#define ull long long
#define uull unsigned long long

int main() {
	string input;
	getline(cin, input);
	//number of test cases we will process
	ull T = stoi(input);

	ull lowerLim;
	ull upperLim;
	ull guessLim; //number of guesses
	ull guess;

	bool finished = false;
	//for each test case
	for (ull i=0; i<T; i++) {
		//get A
		getline(cin, input, ' ');
		lowerLim = stoi(input);
		//get B
		getline(cin, input);
		upperLim = stoi(input);
		//get number of tries we can make
		getline(cin, input);
		guessLim = stoi(input);
		//for that many tries, 
		for (ull j=0; j<guessLim; j++) {
			//we guess the midpull of the range and prull it out
			//+1 because lowerLim is exclusive
			guess = (upperLim+lowerLim+1)/2;
			cout<<guess<<endl;
			getline(cin, input);
			if (input=="TOO_SMALL") {
				lowerLim=guess;
			} else if (input=="TOO_BIG") {
				upperLim=guess;
			} else if (input=="CORRECT") {
				break;
			} else if (input=="WRONG_ANSWER") {
				if (j=guessLim-1) {finished=true;}
				break;
			}
		}
		if (finished) {break;}
	}
	return 0;
}

