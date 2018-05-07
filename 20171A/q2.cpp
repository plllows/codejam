#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define pb push_back

int main() {
	string input;
	getline(cin, input);
	int T = stoi(input);
	cout<<T<<endl;
	int N; //#ingredients
	int P; //#packages

	vector<ll> recipe; //stores amount of each ingredient needed
	//rows are ingredients, cols are #ingredient in a package
	vector<vector<ll>> packages;
	vector<ll> amounts; //lists amounts of an ingredient in a package

for (int t=0; t<T; t++) {
	getline(cin, input, ' ');
	N = stoi(input);
	getline(cin, input);
	P = stoi(input);

	recipe.clear();
	packages.clear();

	//get ingredient ratios
	for (int i=0; i<N; i++) {
		if (i==N-1) {getline(cin, input);}
		else {getline(cin, input, ' ');}
		recipe.pb(stoi(input));
		cout<<input<<" ";
	} cout<<endl;

	for (int i=0; i<N; i++) {
		amounts.clear();
		for (int j=0; j<P; j++) {
			if (j==P-1) {getline(cin, input);}
			else {getline(cin, input, ' ');}
			amounts.pb(stoll(input));
		}

		for (int j=0; j<P; j++) {
			cout<<amounts[j]<<" ";
		}cout<<endl;
		packages.pb(amounts);
	}

	/*
	cout<<"moving"<<endl;

	for (int i=0; i<N; i++) {
		for (int j=0; j<P; j++) {
			if (j==P-1) {cout<<packages[i][j]<<endl;}
			else {cout<<packages[i][j]<<" ";}
		}
	}
	*/


	
}
	return 0;
}