#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
	string input;
	getline(cin, input);
	//getting the number of test cases
	int T = stoi(input);
	//cout<<"T received: "<<T<<endl;

	vector<string> partyNames = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	//tracks parties currently present
	vector<string> parties;
	//keeps count of #senators in corresponding parties
	vector<int> senatorCount;
	//total number of senators present
	int totalPop;
	//number of parties we examine
	int partyCount;
	//INDEX of first, second, actual number of first and second
	int max1, max2, highPop, lowPop;
	
for (int i=0; i<T; i++) {
	parties.clear();
	senatorCount.clear();

	getline(cin, input);
	partyCount = stoi(input);

	//cout<<"#parties received: "<<partyCount<<endl;

	lowPop=0; highPop=0; totalPop=0;
	for (int i=0; i<partyCount; i++) {
		parties.push_back(partyNames[i]);
		if (i==partyCount-1) {getline(cin, input);}
		else {getline(cin, input, ' ');}
		senatorCount.push_back(stoi(input));
		//cout<<"totalPop is: "<<totalPop<<endl;
		totalPop+=senatorCount[i];
		//cout<<"now it is: "<<totalPop<<endl;
		if (senatorCount[i]>=highPop) {
			lowPop=highPop;
			max2=max1;
			highPop=senatorCount[i];
			max1=i;
		}
	}
	//cout<<"initial population is: "<<totalPop<<endl;

	/*ACCOUNT FOR MAX2==MAX1!*/
	cout<<"Case #"<<i+1<<": ";

while (totalPop!=0) {
	//cout<<"popN: "<<totalPop<<" "; 
	if ((totalPop>5)||(totalPop<3)) {
		//cout<<"*first ";
		//removes two if a party is leading by more than 1
		//removes otherwise removes one from both parties
		if (senatorCount[max1]>senatorCount[max2]+1) {
			//cout<<"1* ";
			cout<<parties[max1]<<parties[max1]<<" ";
			senatorCount[max1]-=2;
			totalPop-=2;
		} else {
			//cout<<"2* ";
			cout<<parties[max1]<<parties[max2]<<" ";
			senatorCount[max1]-=1;
			senatorCount[max2]-=1;
			totalPop-=2;
		}
		//if numbers are few, begin protectionist policy
	} else if (totalPop>=4) {
		//cout<<"*second ";
		//if one party is leading over all others, remove one
		//from that party; otherwise remove two from the
		//two top parties
		if (senatorCount[max1]!=senatorCount[max2]) {
			//cout<<"1* ";
			cout<<parties[max1]<<" ";
			senatorCount[max1]-=1;
			totalPop-=1;
		} else {
			cout<<parties[max1]<<parties[max2]<<" ";
			//cout<<"2* ";
			senatorCount[max1]-=1;
			senatorCount[max2]-=1;
			totalPop-=2;
		}
	} else if (totalPop==3) {
		//cout<<"*third* ";
		//in this case we will get rid of just one
		//parties should not be in 2:1 distribution
		//by how we've programmed action from 5th
		cout<<parties[max1]<<" ";
		senatorCount[max1]-=1;
		totalPop-=1;
	}

	lowPop=0; highPop=0;
	for (int i=0; i<partyCount; i++) {
		if (senatorCount[i]>=highPop) {
			lowPop=highPop;
			max2=max1;
			highPop=senatorCount[i];
			max1=i;
		}
	}
}
	cout<<endl;

}

	return 0;
}

