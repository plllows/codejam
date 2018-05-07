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

	string str;
	string temp;
	string last;

	//cout<<('a'>'b')<<endl; //0
	//cout<<('a'<'b')<<endl; //1
	//cout<<('a'=='a')<<endl; //1


for (int t=1; t<=T; t++) {
	cout<<"Case #"<<t<<": ";

	getline(cin, in);
	str = in;

	last=""; last+=str[0]; //initialised with first
	for (int i=1; i<str.length(); i++) {
		//append letter if alphabetically before
		//than first letter in last
		//else prepend it if it comes after the first letter
		if (str[i]<last[0]) {
			//cout<<str[i]<<" before "<<temp[0]<<endl;
			//if str[i] occurs alph before str[0]
			//returns 1
			last+=str[i];
		} else {
			//cout<<str[i]<<" eq or after "<<temp[0]<<endl;
			//if str[i] equals str[0] or comes after it alphabetically
			temp=str[i];
			temp+=last;
			last = temp;
		}
	}

	cout<<last<<endl;


	
}

return 0;
}