#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
	string input;
	getline(cin, input);
	ll T = stoi(input);

	//I will use a vector to keep track of
	//the separation between occupied stalls 
	vector<ull> separation;
	//N stalls, K occupants
	ull N, K;

	//size of largest gap and location of occurrence
	//half of largest gap calculated to save operations
	ll bigGap, bigGapIndex, halfGap;

	//answers for output:
	ull maxLR, minLR;

	//cout<<"T received: "<<T<<endl;
for (ull i=0; i<T; i++) {
	getline(cin, input, ' ');
	N = stoi(input);
	getline(cin, input);
	K = stoi(input);

	separation.clear();
	//initialises the stall with a row of N empty stalls
	vector<ull> tempVector = {N,0};
	separation = tempVector;

for (ull j=0; j<K; j++) {
	//loops four




	//for each occupant that enters
	//find where the largest gap occurs from RIGHT to LEFT
	//so that for two gaps of equal size, the leftmost
	//one will be taken
	//cout<<N<<endl;
	bigGapIndex=distance(separation.begin(), max_element(separation.begin(), separation.end()));
	//cout<<"bigGapIndex is: "<<bigGapIndex<<endl;
	bigGap=separation[bigGapIndex];
	//cout<<"bigGap is: "<<bigGap<<endl;
	/*
	for (ull k=0; k<separation.size(); k++) {
		if (separation[k]>bigGap) {
			bigGap=separation[k];
			bigGapIndex=k;
		}
	}
	*/
	//now, depending on whether bigGap index is even 
	//or odd, we insert a new element next to it
	//to split it accordingly
	halfGap = (bigGap/2);

	if (bigGap%2==0) {
		//if even
		separation[bigGapIndex] = halfGap-1;
		separation.insert(separation.begin()+bigGapIndex, halfGap);
		if (j==K-1) {maxLR=halfGap; minLR=halfGap-1;}
		//cout<<"GOIN OUT"<<endl;
	} else {
		separation[bigGapIndex] = halfGap;
		separation.insert(separation.begin()+bigGapIndex, halfGap);
		if (j==K-1) {maxLR=halfGap; minLR=halfGap;}
		//cout<<"GOIN OUT"<<endl;
	}
}
	cout<<separation.size()<<endl;
	for (int j=0; j<separation.size(); j++) {
		cout<<separation[j]<<" ";
	} 
	cout<<endl;
	cout<<"WTF"
	cout<<"Case #"<<i+1<<": "<<maxLR<<" "<<minLR<<endl;
}


	return 0;
}


