#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define pb push_back

int main() {
	string input;
	getline(cin, input);
	int T =stoi(input);

	int R, C;
	vector<char> row;
	vector<vector<char>> grid;

	bool hasBlank;

	char current;
	for (int t=0; t<T; t++) {
		cout<<"Case #"<<t+1<<": "<<endl;
		getline(cin, input, ' ');
		int R =stoi(input);
		//cout<<"R is: "<<R<<endl;
		getline(cin, input);
		int C =stoi(input);
		//cout<<"C is: "<<R<<endl;

		grid.clear();
		row = vector<char> (C, '?');

		hasBlank=false;
		//initialise the grid from input
		for (int i=0; i<R; i++) {
			getline(cin, input);
			for (int j=0; j<C; j++) {
				row[j]=input[j];
				if (input[j]=='?') {hasBlank=true;}
			}
			grid.pb(row);
			row = vector<char> (C, '?');
		}

		if (hasBlank) {
			//fill in vertically
			for (int j=0; j<C; j++) {
				current=' ';
				for (int i=0; i<R; i++) {
					if (grid[i][j]!='?') {current=grid[i][j];}
					else if (current!=' ') {
						grid[i][j]=current;
					} 
				}
			}

			//vertically reversed
			for (int j=C-1; j>=0; j--) {
				current=' ';
				for (int i=R-1; i>=0; i--) {
					if (grid[i][j]!='?') {current=grid[i][j];}
					else if (current!=' ') {
						grid[i][j]=current;
					} 
				}
			}

			//horizontally - left to right
			for (int i=0; i<R; i++) {
				current=' ';
				for (int j=0; j<C; j++) {
					if (grid[i][j]!='?') {current=grid[i][j];}
					else if (current!=' ') {
						grid[i][j]=current;
					} 
				}
			}

			//vertically reversed
			for (int i=R-1; i>=0; i--) {
				current=' ';
				for (int j=C-1; j>=0; j--) {
					if (grid[i][j]!='?') {current=grid[i][j];}
					else if (current!=' ') {
						grid[i][j]=current;
					} 
				}
			}

			for (int i=0; i<R; i++) {
				for (int j=0; j<C; j++) {
					cout<<grid[i][j];
				}
				cout<<endl;
			}

		} else {
			for (int i=0; i<R; i++) {
				for (int j=0; j<C; j++) {
					cout<<grid[i][j];
				}
				cout<<endl;
			}
		}

		//

	}

	return 0;
}