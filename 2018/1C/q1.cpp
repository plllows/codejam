#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define ld long double
#define pb push_back

void show(vector<string> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<endl;
	}
}

vector<vector<string>> sp; //ith row contains ith letters
vector<string> exist; //words already used
string sol; //our first unique combination

bool rCon(vector<vector<string>> v, string s="", int i=0) {
	//when we have a complete string, check if it is already used

	if (s.length()==v.size()) {
		bool unique = true;

		for (int j=0; j<exist.size(); j++) {
			if (exist[j].compare(s)==0) {
				unique=false;
				break;
			}
		}

		if (unique) {
			sol = s; //sol set to first unique string found
			return true;
		} else {
			return false;
		}
	}

	//for every row in sp we pick a letter
	//append it to a string, and continue to the next index
	string temp;
	for (int j=0; j<v[i].size(); j++) {
		temp = s;
		temp+=v[i][j]; 
		if (rCon(v, temp, i+1)) {
			return true; //stops search once first unique string found
		}
	}

}

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);

	int N, L;

for (int t=1; t<=T; t++) {
	cout<<"Case #"<<t<<": ";
	getline(cin, in, ' ');
	N = stoi(in);
	getline(cin, in);
	L = stoi(in);

	if (N==1) {cout<<"-"<<endl; continue;}

	exist.clear(); sp.clear();
	sol = "-";
	vector<string> blank = {};
	sp = vector<vector<string>> (L, blank);
	//now sp contains L elements - one for each letter index

	//for every word we receive
	for (int i=0; i<N; i++) {
		cin.clear();
		getline(cin, in);

		in = in.substr(0, in.length()-1);
		exist.pb(in);

		//for every letter in the word - jth index
		for (int j=0; j<in.length(); j++) {
			string ph; ph.pb(in[j]);

			//cout<<"inserting letters, ph is: "<<ph<<endl;
			if (sp[j].size()==0) {
				sp[j].pb(ph);
			} else {
				//cout<<"checking duplicacy"<<endl;
				bool dup = false;
				for (int k=0; k<sp[j].size(); k++) {
					if (sp[j][k]==ph) dup=true;
				}

				if (dup==false) {
					sp[j].pb(ph);
				}
			}
		}

	}

	rCon(sp); //populate a vector with all possible solutions

	cout<<sol<<endl;

}

return 0;
}