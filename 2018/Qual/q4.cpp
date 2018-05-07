#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
	string input;
	getline(cin, input);
	int T = stoi(input);

	cout<<fixed;
	cout<<setprecision(10);

	double A;

	double x1, x2, x3;
	double y1, y2, y3;
	double z1, z2, z3;

	double x, y;

	for (int i=0; i<T; i++) {
		cout<<"Case #"<<i+1<<":"<<endl;
		getline(cin, input);
		A = stod(input);
		//cout<<"A is: "<<A<<endl;

		if (A<=1.414213) {
			x3=0;
			y3=0;
			z3=0.5;

			x = A/2.0; 
			//cout<<"x is: "<<x<<endl;

			y = pow(0.5-pow(x,2.0), 0.5);
			//cout<<"y is: "<<y<<endl;

			/*
			we have p1 = (-x, y)
			p2 = (y,x);
			p3 = (x,-y);

			midpoint p1 p2 = ((y-x)/2.0, (x+y)/2.0) 
			midpoint p2 p3 = ((y+x)/2.0, (x-y)/2.0) 
			*/
			x1=(y-x)/2.0;
			y1=(x+y)/2.0;
			z1=0;

			x2=(x+y)/2.0;
			y2=(x-y)/2.0;
			z2=0;
		}

		cout<<x1<<" "<<y1<<" "<<z1<<endl;
		cout<<x2<<" "<<y2<<" "<<z2<<endl;
		cout<<x3<<" "<<y3<<" "<<z3<<endl;
		

	}


	return 0;
}

