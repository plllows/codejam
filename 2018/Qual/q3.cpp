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

	//don't go past these!
	int rightBound;
	int lowBound;

	//true = plowed; false = unplowed;
	vector<vector<bool>> plot;
	vector<bool> row;

	bool complete;
	bool unfilled;

	int lessThanNine;
	int lessThanA;

	for (int i=0; i<T; i++) {
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
		if (A<10) {
			for (int j=0; j<1000; j++) {
				cout<<"2 2"<<endl;
				getline(cin, input);
				if (input=="0 0") {
					complete=true;
					//cout<<"RUN FINISHED"<<endl;
					break;
				} else if (input=="-1 -1") {
					//cout<<"RUN ENDED"<<endl;
					isRunning=false;
					break;
				}
			}
		} else if (A<36) {
			while (width*height<A) {
				height++;
			}
			rightBound=width-1;
			lowBound=height-1;
		} else if (A<81) {
			width=6;
			while (width*height<A) {
				height++;
			}
			rightBound=width-1;
			lowBound=height-1;
		} else if (A<144) {
			width=9;
			while (width*height<A) {
				height++;
			}
			rightBound=width-1;
			lowBound=height-1;
		} else if (A<225) {
			width=15;
			while (width*height<A) {
				height++;
			}
			rightBound=width-1;
			lowBound=height-1;
		}


		//cout<<"width is: "<<width<<" and height is: "<<height<<endl;

		//make a 2d vector to represent plotted land
		for (int j=0; j<width; j++) {
			row.pb (false);
		}
		for (int j=0; j<height; j++) {
			plot.pb (row);
		}

		//cout<<"rect width is: "<<plot.at(0).size()<<" and height is: "<<plot.size()<<endl;
		//cout<<"total area occupied by rectangle is: "<<plot.at(0).size()*plot.size()<<endl;

		

		//while the whole rectangle isnt filled
		while (!complete) {
			cout<<targetx<<" "<<targety<<endl;
			lessThanA++;
			lessThanNine++;

			unfilled=true;

			getline(cin, receivedx, ' ');
			hitx = stoi(receivedx);
			getline(cin, receivedy);
			hity = stoi(receivedy);

			//test input
			if ((hitx==0)&&(hitx==hity)) {
				complete=true;
				break;
			} else if ((hitx==(-1))&&(hitx==hity)) {
				isRunning=false;
				break;
			} else {
				plot[hitx-1][hity-1]=true; //our grid fills from 1,1 but plot starts 0,0
				//cout<<hitx<<" "<<hity<<endl;
			}

			//see if 3x3 around target is filled
			if (lessThanNine>=9) { 
				unfilled=false; //target is initially 2, so we move to 0
				for (int j=targetx-2; j<targetx; j++) {
					for (int k=targety-2; k<targety; k++) {
						if (plot[j][k]==false) {
							unfilled=true;
							complete=false;
							break;
						}
						//cout<<"j and k: "<<j<<" "<<k<<endl;
					}
					if (unfilled) {break;}
				}
			}

			//systematically move across the whole field
			if (!unfilled) {
				if (targety+2<=lowBound) {
					targety+=2;
				} else if (targety+1<=lowBound) {
					targety+=1;
				} else {
					targety=2;
					targetx+=2;
				}
			}

		}




		if (!isRunning) {
			break;
		}
	}
	return 0;
}

