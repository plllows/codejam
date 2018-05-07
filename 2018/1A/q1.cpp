#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int main() {
	string input;
	int T;
	getline(cin, input);
	T = stoi(input);

	int R, C, H, V;
	vector<int> rows;
	vector<int> cols;

	vector<vector<int>> grid;
	vector<int> temp;

	bool rowOK;
	bool colOK;
	bool splitOK;

	int sum1, sum2;
	int rowCut, colCut;

	//for each row and column, count number of things

	for (int i=0; i<T; i++) {
		cout<<"Case #"<<i+1<<": ";
		getline(cin, input,' ');
		R = stoi(input);
		getline(cin, input,' ');
		C = stoi(input);
		getline(cin, input,' ');
		H = stoi(input);
		getline(cin, input);
		V = stoi(input);

		rows.clear();
		cols.clear();
		grid.clear();

		rows = vector<int> (R, 0);
		cols = vector<int> (C, 0);
		temp = vector<int> (C, 0);
		//cout<<"TEMP HAS: "<<temp.size()<<endl;

		rowOK=false; colOK=false; splitOK=false;


		//waffle.clear();
		for (int j=0; j<R; j++) { //row
			getline(cin, input);
			temp = vector<int> (C, 0);
			for (int k=0; k<C; k++) { //column
				if (input[k]=='@') {
					rows[j]++;
					cols[k]++;
					temp[k]++;
				} 
				//if (input[k]=='@') {temp.pb(1);} 
				//else {temp.pb(0)};
			}
			//waffle.pb(temp);
			grid.pb(temp); //grid has R columns and C rows
		}

		//cout<<"GRID HAS "<<grid.size()<<"ROWS and "<<grid[0].size()<<" COLS"<<endl;

		for (int j=0; j<rows.size(); j++) {
			sum1=0; sum2=0;
			for (int k=0; k<j; k++) {
				sum1+=rows[k];
			}
			for (int k=j; k<rows.size(); k++) {
				sum2+=rows[k];
			}
			//cout<<"sum 1 is: "<<sum1<<" sum2 is: "<<sum2<<endl;
			if (sum1==sum2) {rowOK=true; rowCut=j; break;}
		}

		for (int j=0; j<cols.size(); j++) {
			sum1=0; sum2=0;
			for (int k=0; k<j; k++) {
				sum1+=cols[k];
			}
			for (int k=j; k<cols.size(); k++) {
				sum2+=cols[k];
			}
			//cout<<"sum 1 is: "<<sum1<<" sum2 is: "<<sum2<<endl;
			if (sum1==sum2) {colOK=true; colCut=j; break;}
		}

		sum1=0; sum2=0;

		if (rowOK&&colOK) {             //grid has R columns and C rows
			//cout<<"CHECKING"<<endl;
			for (int j=0; j<rowCut; j++) {
				for (int k=0; k<colCut; k++) {
					sum1+=grid[j][k];
				}
			}
			//cout<<"SUM1 is: "<<sum1<<endl;
			for (int j=0; j<rowCut; j++) {
				for (int k=colCut; k<cols.size(); k++) {
					sum2+=grid[j][k];
				}
			}
			if (sum1!=sum2) {colOK=false; rowOK=false;}
			//cout<<"SUM2 is: "<<sum2<<endl;
			sum2=0;
			for (int j=rowCut; j<rows.size(); j++) {
				for (int k=0; k<colCut; k++) {
					sum2+=grid[j][k];
				}
			}
			if (sum1!=sum2) {colOK=false; rowOK=false;}
			//cout<<"SUM2 is: "<<sum2<<endl;
			sum2=0;
			for (int j=rowCut; j<rows.size(); j++) {
				for (int k=colCut; k<cols.size(); k++) {
					sum2+=grid[j][k];
				}
			}
			if (sum1!=sum2) {colOK=false; rowOK=false;}
			//cout<<"SUM2 is: "<<sum2<<endl;
			sum2=0;
		}

		if (rowOK&&colOK) {cout<<"POSSIBLE"<<endl;}
		else {cout<<"IMPOSSIBLE"<<endl;}
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