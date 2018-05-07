#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define ld long double
#define pb push_back

void show(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	} cout<<endl;
}

vector<int> w; //weights of each ant, in order
vector<int> lift; //max weight supported by each ant, in order
vector<int> highstack;
int N; //number of ants

//ID is the base ant, carry is the current weight carried by base, h is current stack height, 
//me is the ID of the last added ant
void fs(int ID=0, int carry=0, int h=0, int me=N) {
	//out of range handling
	cout<<"ID: "<<ID<<" carry: "<<carry<<" h: "<<h<<" me: "<<me<<endl;
	if (me-1<0) {
		//cout<<"returning out of range"<<endl;
		highstack.pb(h); return;
	}

	//for each ant shorter than the last added ant
	for (int i=me-1; i>=0; i--) {
		//if empty stack
		if (h==0) {
			//ID 'i' starts as base ant
			fs(i, 0, h+1, i);
			//cout<<"new base ant, ID: "<<ID<<endl;
			continue;
		} 

		//if amt carried + weight of new ant exceeds limit of base ant
		cout<<"current lift: "<<lift[ID]<<" new weight: "<<w[i]<<endl;
		if ((carry+w[i])>lift[ID]) {
			//cout<<"returning weight exceeded"<<endl;
			highstack.pb(h); return;
		} else {
			//increment carry and height and meID
			//cout<<"new ant added"<<endl;
			fs(ID, carry+w[i], h+1, i);
		}
	}
}

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);


for (int t=1; t<=T; t++) {
	cout<<"Case #"<<t<<": ";
	highstack.clear();
	lift.clear(); w.clear();
	getline(cin, in);
	N = stoi(in);
	for (int i=0; i<N; i++) {
		if (i==N-1) {getline(cin, in);}
		else {getline(cin, in, ' ');}
		w.pb(stoi(in));
		lift.pb(6*stoi(in));
	}

	if (t==3) {
		show(w);
		show(lift);
	}

	//cout<<"calling fs"<<endl;
	fs();
	//cout<<"end"<<endl;

	int max=0;
	for (int i=0; i<highstack.size(); i++) {
		if (highstack[i]>max) max = highstack[i];
	}

	cout<<max<<endl;
}	

return 0;
}