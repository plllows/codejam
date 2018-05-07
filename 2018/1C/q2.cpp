#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define ld long double
#define pb push_back

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);
	int N, D, sum;

	double lo; //least occuring probability
	int loF; //least occuring flavour

	vector<int> total; //total given for each flavour
	vector<bool> ava; //is the flavour still available?

for (int t=1; t<=T; t++) {
	getline(cin, in);
	N = stoi(in);
	sum=0; 				//all preferences shown
	total = vector<int> (N, 0); //keeps total occurences of each flavour
	ava = vector<bool> (N, true);

//for each customer
for (int n=0; n<N; n++) {
	getline(cin, in, ' ');
	D = stoi(in);

	if (D==0) {
		cout<<-1<<endl;
		continue;
	}

	lo = 100;
	loF =-1;

	//for every flavour
	for (int i=0; i<D; i++) {
		if (i==D-1) {getline(cin, in);} 
		else {getline(cin, in, ' ');} //get the flavour

		total[stoi(in)]++;	//increment occurence
		sum++;

		double temp = (double)total[stoi(in)]/(double)sum; //occurrence rate of current flavour among all flavours of all customers
		if ((temp<lo) && (ava[stoi(in)])) { //if it is the lowest which is still available
			lo = temp;		//lo is the lowest occurence rate
			loF = stoi(in); //and loF is the lowest occuring flavour
		}
	}
	//fl contains the flavours favoured by each customer

	/*every time we get a flavour we check the $occurence
	to see which flavour allowed by the customer has
	the least*/
	cout<<loF<<endl;
	if (loF!=-1) {ava[loF] = false;}
}
}

return 0;
}