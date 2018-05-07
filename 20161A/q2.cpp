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

int main() {
	string in;
	getline(cin, in);
	int T = stoi(in);
	int N;

	vector<vector<int>> list; //N-1 lists
	vector<int> temp;
	int min, max;
	bool isMin, isMax;
	vector<vector<int>> sl; //ones containing the max
	vector<vector<int>> sh; //ones containing the min

	vector<vector<int>> h; //filling in horizontally
	vector<vector<int>> v; 	//filling in vertically

for (int t=1; t<=T; t++) {
	getline(cin, in);
	N = stoi(in);
	list.clear();
	sl.clear(); sh.clear(); 
	max=0; min=2500;

	for (int i=0; i<2*N-1; i++) {
		isMin=false; isMax=false;
		temp.clear();
		for (int j=0; j<N; j++) {
			if (j==N-1) getline(cin, in);
			else getline(cin, in, ' ');
			if (stoi(in)>=max) {max=stoi(in); isMax=true;}
			if (stoi(in)<=min) {min=stoi(in); isMin=true;}
			temp.pb(stoi(in));

		}
		show(temp);
		list.pb(temp);
		if (isMin) sl.pb(temp);
		if (isMax) sh.pb(temp);
	}

	//find the double occurence
	int counter=0;
	for (int i=0; i<sl.size(); i++) {
		if (sl[0][0]!=min) {
			sl.erase(sl.begin());
		} else {break;} //left with only ones with min	
	}

	cout<<sh.size()<<" "<<max<<endl;
	counter=0;
	for (int i=0; i<sh.size(); i++) {
		if (sh[0][N-1]!=max) {
			sh.erase(sh.begin());
		} else {break;} //left with only ones with max
	}

	for (int i=0; i<list.size(); i++) { //remove max and min from list
		for (int j=0; j<sl.size(); j++) {
			if (list[i]==sl[j]) {
				list.erase(list.begin+i);
				i--;
			}
		}
		for (int j=0; j<sh.size(); j++) {
			if (list[i]==sh[j]) {
				list.erase(list.begin+i);
				i--;
			}
		}
	}

	cout<<"max and min count: "<<sh.size()<<" "<<sl.size()<<endl;

	h = vector<vector<int>> (N, vector<int> (N,-1));
	v = vector<vector<int>> (N, vector<int> (N,-1));
	


	grid = list;
	//if border colrow are all present
	if (sh.size()==2 && sl.size()==2) {

		//match the end points up
		if ((sl[0][N-1]!=sh[0][0])&&(sl[0][N-1]==sh[1][0])) {
			//if end of sl[0] matches start of sh[1] not sh[0]
			//swap sh[1] and sh[0]
			_v = sh[1];
			sh[1] = sh[0];
			sh[0] = _v;
		}

		if ((sl[1][N-1]!=sh[1][0]) || (sl[0][N-1]!=sh[0][0])) {cout<<"NOT A SQUARE"<<endl; return 1;}

		//maybe check all end points match to form a square

		//now find rows and columns that match the end points of the horizontal ones - any will do?
		for (int i=0; i<list.size(); i++) {
			for (int j=0; j<N; j++) {
				if (list[i][0]==sl[0][1] && list[i][N-1]==sh[0][N-1]) {
					list[i]
				}
			}
		}

	}
	
	
}

return 0;
}