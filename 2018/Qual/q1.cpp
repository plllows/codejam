#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int main() {
	string Loops;
	getline(cin, Loops);
	int T=stoi(Loops);
	
	string DLimit;
	ll DLim;
	string Prog;

	vector<int> Shots = {};

	ll currentDamage;
	ll rawDamage;
	int shotCounter;
	int switches;
	int iter;
	for (int i=0; i<T; i++) {
		cout<<"Case #"<<i+1<<": ";
		getline(cin, DLimit, ' '); getline(cin, Prog);
		DLim=stoi(DLimit);
		//cout<<"DLim is: "<<DLim<<endl;
		Shots.clear();

		if (Prog.find("S")<0) { //if no shoot in program
			cout<<"0"<<endl;
			continue;
		}

		currentDamage=1;
		rawDamage=0; //damage by original program
		switches=0; //#switches made
		shotCounter=0;

		for (int j=0; j<Prog.length(); j++) {
			switch (Prog[j]) {
				case 'S': 
				Shots.pb (currentDamage);
				rawDamage+=currentDamage;
				//cout<<currentDamage<<" ";
				shotCounter++;
				break;
				case 'C':
				currentDamage*=2;
				break;
			}
		}//cout<<endl;

		if (rawDamage<=DLim) { //if raw damage less than D
			cout<<"0"<<endl;
			continue;
		}  else if (shotCounter>DLim) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}

		while (rawDamage>DLim) {
			iter = distance(Shots.begin(), max_element(Shots.begin(), Shots.begin()+Shots.size()));
			//cout<<"current damage is: "<<rawDamage<<endl;
			Shots.at(iter)/=2;
			//cout<<"reducing by: "<<Shots.at(iter)<<endl;
			rawDamage-=Shots.at(iter);
			switches++;
		} 
		//cout<<"currentDamage is: "<<rawDamage<<endl;

		cout<<switches<<endl;

	}

	return 0;
}

