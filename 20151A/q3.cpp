#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define ld long double
#define pb push_back

void showShow(vector<vector<int>> v) { //print out all elements of 2d vector
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v[i].size(); j++) {
			cout<<v[i][j]<<" ";
			if (v[i][j]==-1 && i!=j) {cout<<"ERROR"<<endl;}
		}
		cout<<endl;
	}
}

void testSym(vector<vector<int>> v) { //test symmetry of dp
	for (int i=0; i<v.size(); i++) {
		for (int j=i; j<v[i].size(); j++) {
			if (v[i][j]!=v[j][i]) {cout<<"ERROR"<<endl; exit(1);}
		}
	}
}

void show(vector<int> v) { //print out all elements of 1d vector
	for (int i=0; i<v.size(); i++) {
		cout<<v[i]<<endl;
	}
}

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);
	int N; //#trees
	vector<ld> x, y;
	vector<vector<int>> dp; //dynamic programming matrix
	vector<int> sol; //minimum value of each row in dp
	vector<int> queue; //for multiple points on the same line
	ld m; //slope of line
	ld yitcp; //y intercept of line

	int higher, lower; //#points above/below line

	ld ty; //temp y-val for calculation
	int least; //temp integer for finding minimum


for (int t=1; t<=T; t++) {
	cout<<"Case #"<<t<<":"<<endl;
	getline(cin, in);
	N = stoi(in);
	x.clear(); y.clear(); sol.clear();
	m=0; yitcp=0; higher=0; lower=0; ty=0; least=0;

	for (int i=0; i<N; i++) {
		getline(cin, in, ' ');
		x.pb(stold(in));
		getline(cin, in);
		y.pb(stold(in));
	}

	dp = vector<vector<int>> (N, vector<int> (N, -1));
	//N by N - jth column of ith row is #points in smaller half created by line from point i to point j
	sol = vector<int> (N, N);

	//showShow(dp);
	//DP! - x-y mincount == y-x mincount

	//for each point, draw a line to every other point
	//for every line, examine each other points to check
	//whether they are greater or lesser
	//than the current line.
	//the global minimum of all less/greater vals
	//is the minimum # trees need to die
	//exxamine vertical line separately by comparing
	//horizontal coordinates
	if (N==1) {
		cout<<"0"<<endl;
		continue;
	}
	//for every point
	for (int i=0; i<N; i++) {
		//partnering with every other point
		for (int j=0; j<N; j++) {
			if (j==i) continue;

			if (dp[i][j]!=-1) { //if already calculated, skip
				continue;
			}

			//test line against every other point to find least populated half
			higher=0; lower=0;
			queue.clear();

			//calculate line from ith point to jth point
			//no dividing by infinity today
			if (x[j]!=x[i]) {
				m = (y[j]-y[i])/(x[j]-x[i]);

				//calculate y-intercept
				yitcp = (-m*x[i]+y[i]);

				for (int k=0; k<N; k++) {
					if ((k==i) || (k==j)) continue;
					//calculate their y val using equation
					ty = m*x[k]+yitcp;
				
					//then compare to their true y-val
					if (ty>y[k]) {
						lower++;
					} else if (ty < y[k]) {
						higher++;
					} else if (ty==y[k]) {
						queue.pb(k); //other points on same line can be solved
					}
				}
			
			} else {
				//vertical lines
				for (int k=0; k<N; k++) {
					if ((k==i) || (k==j)) continue;
					//compare their x value to our own
					if (x[k]<x[i]) {
						lower++;
					} else if (x[k]>x[i]) {
						higher++;
					} else if (x[k]==x[i]) {
						queue.pb(k); //other tree numbers that lie on same line
					}
				}
			}

			dp[i][j]=min(higher, lower); //set to least populated half
			dp[j][i]=min(higher, lower);
			//show(queue);
			for (int k=0; k<queue.size(); k++) {
				dp[i][queue[k]] = dp[i][j]; //other points which lie on same line
				dp[queue[k]][i] = dp[i][j]; //can be solved at the same time
				dp[j][queue[k]] = dp[i][j]; //i.e. lines from those points to x and y and vice versa
				dp[queue[k]][j] = dp[i][j];
			}
		}
	}

	//find the minimum value in every row of dp
	for (int i=0; i<dp.size(); i++) {
		least = N;
		for (int j=0; j<dp[i].size(); j++) {
			if ((dp[i][j] < least) && (dp[i][j]!=-1) ){
				least = dp[i][j];
			}
		}
		sol[i] = least;
	}
	//testSym(dp);
	show(sol); //display solution; same format as solution for each case
}

return 0;
}