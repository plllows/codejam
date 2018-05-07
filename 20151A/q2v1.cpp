#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define pb push_back

void show(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	}cout<<endl;
}

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);
	int B, N, ts;
	vector<int> m, c;
	bool served;

for (int t=1; t<=T; t++) {
	cout<<"Case #"<<t<<": ";
	getline(cin, in, ' ');
	B = stoi(in);
	getline(cin, in);
	N = stoi(in);
	m.clear();

	//cout<<"B, N: "<<B<<" "<<N<<endl;


	for (int i=0; i<B; i++) {
		if (i==B-1) {getline(cin, in);}
		else {getline(cin, in, ' ');}
		m.pb(stoi(in));
	}
	c = vector<int> (B, 0); //counter for each barber

	//show(m);
	

	ts=0; served=false;

	for (int i=0; i<INT_MAX; i++) {
		for (int j=0; j<c.size(); j++) {
			//if counter==0 means new customer can be served
			if (c[j]==0) {
				N--; ts++; //count your place in the queue
				//cout<<"served by "<<j<<" N is now:"<<N<<endl;
				if (N==0) {
					cout<<j+1<<endl;
					served=true;
				}
			}
			c[j]++; //once we reach limit, reset c
			if (c[j]==m[j]) {
				c[j]=0; 
			}
			if (served) break;
		}
		if(served) break;
	}
	

}

	return 0;
}