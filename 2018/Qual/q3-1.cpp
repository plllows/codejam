#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

int main() {
	string input;
	getline(cin, input);
	int T = stoi(input);

	int A;

	bool isRunning=true;

	//initial coords 2 2
	//width and height of our target rectangle
	int width;
	int height;

	//borders are 2 and 99 - hard borders
	//the ones we target
	int targetx;
	int targety;

	//the ones the donkey plows
	string receivedx;
	string receivedy;
	int hitx;
	int hity;

	//true = plowed; false = unplowed;
	vector<vector<bool>> plot;
	vector<bool> row;

	bool complete;
	bool unfilled;
	bool colComplete;

	int lessThanNine;
	int lessThanA;

	for (int i=0; i<T; i++) {
		//set up for each test case
		getline(cin, input);
		A = stoi(input); //minimum area
		width=3;
		height=3;
		plot.clear();
		isRunning=true;
		complete=false;

		targetx=2;
		targety=2;

		lessThanNine=0;
		lessThanA=0;

		//brute force the small ones
		if (A==20) {
			width=3; //number of columns
			height=7; //number of rows
		} else if (A==200) {
			width=15;
			height=14;
		}

		//cout<<"width is: "<<width<<" and height is: "<<height<<endl;

		//make a 2d vector to represent plotted land
		for (int j=0; j<width; j++) {
			row.pb (false);
		}
		for (int j=0; j<height; j++) {
			plot.pb (row);
		}

		//fills the whole rectangle in this while loop
		while (!complete) {
			cout<<targetx<<" "<<targety<<endl;
			//the targeted row, and the targeted column

			getline(cin, receivedx, ' ');
			hitx = stoi(receivedx); //the row that was hit
			getline(cin, receivedy);
			hity = stoi(receivedy); //the column that was hit

			//test input
			if ((hitx==0)&&(hitx==hity)) { //success!
				break;
			} else if ((hitx==(-1))&&(hitx==hity)) { //faulted
				isRunning=false;
				break;
			} else {
				plot[hitx-1][hity-1]=true; //our grid fills from 1,1 but plot starts 0,0 to 0 2
			}

			//see if row of 3 above target is filled -if so, shift downwards
			unfilled=false;
			colComplete=false;
			for (int j=0; j<3; j++) {
				if (plot[targetx-2][targety-2+j]==false) {
					unfilled=true;
				}
			}

			//if target has reached the bottom limit, check also for the rows on and below targetx
			if ((targetx==height-1)&&(!unfilled)) {
				colComplete=true;
				for (int j=1; j>=0; j--) {  //this one goes through 2 rows on and below targetx
					for (int k=0; k<3; k++) { //this one goes through 3 columns around targety
						if (plot[targetx-j][targety-2+k]==false) {
							colComplete=false;
						}
					}
				}
			}

			//if 3x3 around target is all filled, 
			if (colComplete) {
				targetx=2; //resets row to the top
				targety+=2; //pushes y over
			} else if ((!unfilled)&&(targetx+1<height)) {
				targetx++;
			}
		}




		if (!isRunning) {
			break;
		}
	}
	return 0;
}

