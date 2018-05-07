#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int factorial(int n) {
	if (n==1) {return 1;}
	if (n==0) {return 1;}
	return n*factorial(n-1);
}

void subset(int n) {

}

int main() {
	string input;
	getline(cin, input); 
	int T = stoi(input);

	int R, C;
	ll B;

	//stores data for all cashiers
	vector<vector<int>> allCashiers = {};
	vector<vector<int>> cashiers = {};
	//takes input for a particular cashier
	vector<int> cashier = {};

	int fastest;
	int slowest;
	int currentRecord;
	int lowestRecord;
	bool optimised;
	int difference;
	int counter;

	vector<int> perm;
	vector<int> perms;

	for (int i=0; i<T; i++) {
		cout<<"Case #"<<i+1<<": ";
		getline(cin, input, ' ');
		R = stoi(input);
		getline(cin, input, ' ');
		B = stoi(input);
		getline(cin, input);
		C = stoi(input);

		allCashiers.clear();
		perms.clear();
		for (int j=0; j<C; j++) {
			//for each cashier
			cashier.clear();
			getline(cin, input, ' ');
			cashier.pb(stoi(input));
			//max capacity
			getline(cin, input, ' ');
			cashier.pb(stoi(input));
			//time per item
			getline(cin, input);
			cashier.pb(stoi(input));
			//after interaction

			cashier.pb(0);
			//number of bits given to cashier - index 3

			cashier.pb(0);
			//amount of time cashier needs to use - index 4

			allCashiers.pb(cashier);
			//place cashier into the ranks
		}

		//restrictions based on how many robots there are -i.e. how many cashiers can be used at once!!!!
		//calculate the R out of M cashiers that has capacity to handle B, and does it in the fastest time???

		//now, to distribute the bits and calculate minimum time
		for (int j=0; j<cashiers.size(); j++) {
			//see if bits bigger than max
			if (B>cashiers[j][0]) {
				//if so, fill with max capacity
				cashiers[j][3]=cashiers[j][0];
				B-=cashiers[j][0];
				//and calculate the time
				cashiers[j][4]=cashiers[j][1]*cashiers[j][3]+cashiers[j][2];
			}  else {
				//if max capacity greater than bits remaining
				cashiers[j][3]=B;
				B=0;
				//and calculate the time
				cashiers[j][4]=cashiers[j][1]*cashiers[j][3]+cashiers[j][2];
			}
			if (B==0) {break;}
		}

		//now redistribute the bits among the cashiers depending
		//the difference between the fastest cashier and the slowest cashier
		//give bits from the slowest cashier
		//to all the other cashiers?

		optimised=false;
		counter=0;
		lowestRecord=99999999;
		cout<<"GOING INTO THE LOOP"<<endl;


		while (!optimised) {
			//find index of fastest and slowest cashiers
			fastest=0;
			slowest=0;
			for (int j=1; j<cashiers.size(); j++) {
				if (cashiers[j][4]<cashiers[fastest][4]) {
					if (cashiers[j][3]<cashiers[j][0]) {
						//cannot be marked as fastest
						//if you are working at capacity
						fastest=j;
					}
				}
				if (cashiers[j][4]>=cashiers[slowest][4]) {
					slowest=j;
				}
			}
			//test if slowest time has decreased
			currentRecord=cashiers[slowest][4];
			cout<<"currentrec: "<<currentRecord<<endl;
			if (currentRecord<lowestRecord) {
				lowestRecord=currentRecord;
				counter=0;
			} else {
				counter++;
			}

			if (counter==8) {optimised=true; continue;}
			//now we have found the fastest and the slowest
			//find the difference between their bits
			//and the slowest one will give half the difference
			//to the faster one.

			cashiers[slowest][3]-=1;
			cashiers[fastest][3]+=1;


			/*
			difference = (cashiers[slowest][3]-cashiers[fastest][3]+1)/2;
			if (difference>(cashiers[fastest][1]-cashiers[fastest][3])) {
				difference=cashiers[fastest][1]-cashiers[fastest][3];
				//make sure adding the difference won't exceed limits
				cashiers[slowest][3]-=difference;
				cashiers[fastest][3]+=difference;
			}
			*/

			//recalculate the times
			cashiers[fastest][4]=cashiers[fastest][1]*cashiers[fastest][3]+cashiers[fastest][2];
			cashiers[slowest][4]=cashiers[slowest][1]*cashiers[slowest][3]+cashiers[slowest][2];
			
		}
		cout<<cashiers[slowest][4]<<endl;
	}

	return 0;
}

/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/
/*GOOGLE PLEASE HIRE ME*/

