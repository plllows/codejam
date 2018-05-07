#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define pb push_back

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);
	int N;
	vector<double> plate;
	long sum1, sum2;
	long md, spd;


for (int t=0; t<T; t++) {
	cout<<"Case #"<<t+1<<": ";
	getline(cin, in);
	N =stoi(in);
	plate.clear();
	sum1=0; sum2=0;
	md=0;
	for (int i=0; i<N; i++) {
		if (i==N-1) {
			getline(cin, in);
		} else {
			getline(cin, in, ' ');
		}
		plate.pb(stoi(in));
		if ((i>0)&&(plate[i]<plate[i-1])) {
			sum1+=plate[i-1]-plate[i];
			if (plate[i-1]-plate[i] > md) {
				md =plate[i-1]-plate[i];
			}
		}
	}

	//cout<<"speed is:"<<spd<<endl;
	spd=md; //#mushroom eaten in 10s
	// md/10 is rate of mushroom consumption

	for (int i=1; i<N; i++) {
		//if plate contained more or eq than 
		//mushroom in 10s
		//we consume maximum mushrooms
		if (plate[i-1]>=spd) {
			sum2+=spd;
		} else {
			//otherwise we eat as mucha s the plate
			//holds
			sum2+=plate[i-1]; //if we have empty plate at some point
		}
	}

	cout<<sum1<<" "<<sum2<<endl; //method 1



}



	return 0;
}

