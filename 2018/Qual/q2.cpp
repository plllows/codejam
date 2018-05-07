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

	string input;

	int N; //number of values in list
	vector<long> set1 = {}; //first set (even indexed)
	vector<long> set2 = {}; //second set (odd indexed)

	long iter1; //iterators for each set
	long iter2; //to locate the bad value
	long cc; //comparison counter;
	bool badVal;

	long j;

	//eachvi can go up to 10^9
	for (int i=0; i<T; i++) {
		cout<<"Case #"<<i+1<<": ";
		getline(cin, input);
		N = stoi(input);
		set1.clear();
		set2.clear();
		for (j=0; j<N; j++) {
			if (j%2==0) {
				//even index goes into set 1
				if (j==N-1) {getline(cin, input);}
				else {getline(cin, input, ' ');}
				set1.pb (stoi(input));
			} else {
				//odd index goes into set 2
				if (j==N-1) {getline(cin, input);}
				else {getline(cin, input, ' ');}
				set2.pb (stoi(input));
			}
		}

		/*cout<<"set1 size: "<<set1.size()<<endl;
		for (j=0; j<set1.size(); j++) {
			cout<<set1.at(j)<<" ";
		} cout<<endl;
		cout<<"set2 size: "<<set2.size()<<endl;
		for (j=0; j<set2.size(); j++) {
			cout<<set2.at(j)<<" ";
		} cout<<endl;
		*/

		sort(set1.begin(), set1.end());
		sort(set2.begin(), set2.end());

		cc=0;
		badVal=false;

		//depending on whether #values is even
		//earlier values should be smaller
		if (N%2==0) { 
			if (set1.at(0)>set2.at(0)) {
				cout<<cc<<endl;
				continue;
			} cc++; //cc starts at 1 here
			for (j=0; j<set2.size()-1; j++) {
				//cout<<"even: "<<j<<endl;
				if (set2.at(j)>set1.at(j+1)) {
					cout<<cc<<endl;
					badVal=true;
					break;
				} 

				if (set1.at(j+1)>set2.at(j+1)) {
					cc++;
					cout<<cc<<endl; //cc starts at 2 here
					badVal=true;
					break;
				}
				cc+=2; // if none found, cc+=2
			}
		} else {
			for (j=0; j<set1.size()-1; j++) {
				if (set1.at(j)>set2.at(j)) {
					cout<<cc<<endl; //cc starts at 0
					badVal=true;
					break;
				} 
				if (set2.at(j)>set1.at(j+1)) {
					cc++;
					cout<<cc<<endl; //cc starts at 1
					badVal=true;
					break;
				}
				cc+=2; //if none found, cc+=2;
			}
		}

		if (badVal==false) {
			cout<<"OK"<<endl;
		}


	}



	return 0;
}