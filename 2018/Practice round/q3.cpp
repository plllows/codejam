#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
	string input;
	getline(cin, input);
	ll T = stoi(input);
	//cout<<"T received: "<<T<<endl;
	cout<<fixed;
	cout<<setprecision(6);
	//cout<<"T received: "<<T<<endl;

	ull dest;
	ll horseCount;
	float stopWatch, maxTime, AnnieSpeed;
	vector<ull> horseLocations;
	vector<ll> horseSpeeds;

	ll counter, index;

for (ll i=0; i<T; i++) {
	getline(cin, input, ' ');
	dest =stoi(input);
	//cout<<"dest received: "<<dest<<endl;
	getline(cin, input);
	horseCount=stoi(input);
	//cout<<"hCount received: "<<horseCount<<endl;

	maxTime=0;
	stopWatch=0;
	horseLocations.clear();
	horseSpeeds.clear();

	//initialising horses
	for (ll j=0; j<horseCount; j++) {	
		getline(cin, input, ' ');
		horseLocations.push_back(stoi(input));
		//cout<<"hLocation received: "<<horseLocations[j]<<endl;
		getline(cin, input);
		horseSpeeds.push_back(stoi(input));
		//cout<<"hSpeed received: "<<horseSpeeds[j]<<endl;
		stopWatch = (float)(dest-horseLocations[j])/horseSpeeds[j];
		//cout<<"time taken for "<<j<<"th horse to finish is: "<<stopWatch<<endl;
		//calculates maximum time
		if (stopWatch>maxTime)  {maxTime= stopWatch;}
	}

	AnnieSpeed=((float)dest/maxTime);
	cout<<"Case #"<<i+1<<": "<<AnnieSpeed<<endl;
}
	return 0;
}

