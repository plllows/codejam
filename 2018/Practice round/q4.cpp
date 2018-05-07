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
	separation.push_back(N);

for (ull j=0; j<min(K,(T+4)/2); j++) {
	bigGapIndex=distance(separation.begin(), max_element(separation.begin(), separation.end()));
	bigGap=separation[bigGapIndex];

	halfGap = (bigGap/2);
	if (bigGap==1) {
		separation.erase(separation.begin()+bigGapIndex);
		if (j==K-1) {maxLR=0; minLR=0;}
	} else if (bigGap%2==0) {
		//if even
		if ((halfGap-1)>0) {separation[bigGapIndex] = halfGap-1;}
		else {separation.erase(separation.begin()+bigGapIndex);}
		if (halfGap>0) {separation.insert(separation.begin()+bigGapIndex, halfGap);};
		if (j==K-1) {maxLR=halfGap; minLR=halfGap-1;}
		//cout<<"GOIN OUT"<<endl;
	} else {
		if (halfGap>0) {separation[bigGapIndex] = halfGap;}
		else {separation.erase(separation.begin()+bigGapIndex);}
		if (halfGap>0) {separation.insert(separation.begin()+bigGapIndex, halfGap);}
		if (j==K-1) {maxLR=halfGap; minLR=halfGap;}
		//cout<<"GOIN OUT"<<endl;
	}
}
	//for (int j=0; j<separation.size(); j++) {cout<<separation[j]<<" ";} cout<<endl;
	cout<<"Case #"<<i+1<<": "<<maxLR<<" "<<minLR<<endl;
}


	return 0;
}

