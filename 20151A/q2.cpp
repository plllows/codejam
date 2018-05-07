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
	ll B, N, ts; //ts: total served + assigned at a particular time
	ll up, low, mid; //binary search var

	ll mt, mint; //maxtime, token
	vector<int> m, c; //stores cut-times and counters
	bool served;

for (int t=1; t<=T; t++) {
	cout<<"Case #"<<t<<": ";
	getline(cin, in, ' ');
	B = stoll(in);
	getline(cin, in);
	N = stoll(in);
	m.clear(); mt = 0; mint=-1; 

	//cout<<"B, N: "<<B<<" "<<N<<endl;
	for (int i=0; i<B; i++) {
		if (i==B-1) {getline(cin, in);}
		else {getline(cin, in, ' ');}
		m.pb(stoll(in));
		if (stoll(in)>mt) {mt=stoll(in);} //takes mt to be time of slowest barber
	}
	c = vector<int> (B, 0); //counter for each barber

	if (N<=B) {
		cout<<N<<endl;
		continue;
	}

	//show(m);
	//BINARY SEARCH TIME
	up = mt*N+2; //strict upper bound: slowest barber handles all customers + 2 just to be safe
	low = -1; //just for the lols
	mid = (up+1+low)/2;
	do {
		if (mint!=-1) { 
			if (ts>=N) { //if customers served & assigned at time mid exceeds N, we lower our boundaries
				up=mid;
				mid=(up+1+low)/2;
			} else {
				low=mid;
				mid=(up+1+low)/2;
			}
		}

		ts=0;
		mint=mt; //change bounds for future iterations
		for (int i=0; i<m.size(); i++) {
			ts+=(mid/m[i])+1; //how many customers barber [i] has served at time mid + the one they're currently serving
			c[i] = mid % m[i]; //how long since barber[i] started serving the current customer
		}
		//cout<<ts<<" served and assigned at time: "<<mid<<endl;
	} while (!((N-B-1)<=ts && ts<N)); // mid is some time before N customers have been served in total
	//cout<<"loop exit"<<endl;

	served=false;
	N-=ts; //your place in queue advanced by how many customers served so far
	//cout<<"currently, N is: "<<N<<" and mid is: "<<mid<<endl;
	//then search up from time mid to find the barber that changes N -> 0
	//show(c);
	for (ll i=mid; i<LLONG_MAX; i++) {
		//cout<<"searching time: "<<i<<endl;
		for (int j=0; j<c.size(); j++) {

			c[j]++;
			
			if (c[j]==m[j]) { //once a counter reaches barber's cuttime, reset to 0
				c[j]=0; 
			}

			//if counter==0 means new customer can be served
			if (c[j]==0) {
				N--; //queue advances each time
				//cout<<"served by "<<j+1<<" N is now:"<<N<<endl;	
			}

			//once N==0, we've found our man
			if (N==0) {
				cout<<j+1<<endl;
				served=true;
				break;
			}
		}
		if(served) break;
	}
	

}

	return 0;
}