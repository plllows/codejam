#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long
#define ll long long
#define pb push_back

int main() {
	string input;
	getline(cin, input);
	int T = stoi(input);

	//#participants, #currently stated lang, number of partipants not yet evald
	int N, L, remainder;

	//val of single vote
	double single;

	//distribution of languages
	vector<double> dist;

	//count #g between 0.5 and 1
	int counter0;
	int total;

	int sumRespond;

for (int t=1; t<=T; t++) {
	getline(cin, input, ' ');
	N = stoi(input);
	getline(cin, input);
	L = stoi(input);

	//get distributions
	dist.clear();
	counter0=0; sumRespond=0;
	for (int i=0; i<L-1; i++) {
		getline(cin, input, ' ');
		dist.pb(stoi(input));
		sumRespond+=stoi(input);
	}
	getline(cin, input);
	dist.pb(stoi(input));
	sumRespond+=stoi(input);

	remainder=N-sumRespond;

	//creating empty slots
	for (int i=0; i<remainder; i++) {
		dist.pb(0);
	}

	//value of a single vote
	single = (1.0/N)*100;
	//cout<<"single is: "<<single<<endl;

	//normalise group distributions
	for (int i=0; i<dist.size(); i++) {
		dist[i]/=N; dist[i]*=100; //expressed as percentage of N
		//count #0group in original
		if (dist[i]-(double)floor(dist[i])>=dist[i]-(double)ceil(dist[i])) {
			counter0++;
		}
	}

	double counter=0; 
	total=0;
	//maximise count of 0.5<=dist[i]<1
	//or maximise value?

	//solve case single between 0.5 and 1
	//cout<<single-(double)floor(single)<<endl;
	//cout<<single-(double)ceil(single)<<endl;
	if (single==(double)floor(single)) {
		cout<<"Case #"<<t<<": "<<100<<endl;
	} else if ((fabs(single-(double)floor(single))>=fabs((double)ceil(single)-single))) {
		//cout<<"PATH ONE"<<endl;
		for (int i=L; i<dist.size(); i++) {
			dist[i] = single;
		}
		for(int i=0; i<dist.size(); i++) {
			//if we get to round up
			//cout<<dist[i]<<endl; 
			if ((dist[i]-(double)floor(dist[i])>=(double)ceil(dist[i])-dist[i])&&(dist[i] != floor(dist[i]))) {
				counter++;
			}
		}
		//cout<<"counter: "<<counter<<endl;
		//calculate total percentage - truncated as ints
		for (int i=0; i<dist.size(); i++) {
			total+=(int)(dist[i]);
		}
		total+=counter;
		cout<<"Case #"<<t<<": "<<total<<endl;
	} else {
		//for single between 0 and 0.5...
		counter=1.0;
		double token, multiplier;
		bool madeChange;
		while (remainder!=0) {
			if (remainder < counter) {
				multiplier = remainder;
			} else {
				multiplier = counter;
			}
			//cout<<"multiplier is: "<<multiplier<<endl;
			madeChange=false;
			for (int i=0; i<dist.size(); i++) {
				token = dist[i]+multiplier*single;
				//if the groups aren't already getting rounded up
				if (fabs(dist[i]-(double)floor(dist[i]))<fabs((double)ceil(dist[i])-dist[i])) {
					if (fabs(token-(double)floor(token))>=fabs((double)ceil(token)-token)) {
						dist[i] = token;
						remainder-=multiplier;
						if (remainder < counter) {
							multiplier = remainder;
						} else {
							multiplier = counter;
						}
						madeChange=true;
						//cout<<"Made a change: new dist["<<i<<"]: "<<dist[i]<<endl;
					}
					//if (dist[i]==0) {cout<<"0 IS PART OF FIRST OPTION"<<endl;}
				} 
			}


			//if we've gone thorugh and can't add any more
			if (madeChange==false && counter>remainder) {
				while (remainder!=0) {
					for (int i=0; i<dist.size(); i++) {
						if (dist[i]==0) {
							dist[i]=single;
							remainder--;
							break;
						}
					}
				}
				break;
			}
			counter++;
		}
		counter=0;
		//printf("%s\n", "start");
		for(int i=0; i<dist.size(); i++) {
			//if we get to round up
			if ((dist[i]-(double)floor(dist[i])>=(double)ceil(dist[i])-dist[i])&&(dist[i] != floor(dist[i]))) {
				counter++;
				//cout<<dist[i]<<endl;
			}
		}
		//cout<<"counter: "<<counter<<endl;
		//calculate total percentage - truncated as ints
		for (int i=0; i<dist.size(); i++) {
			total+=(int)(dist[i]);
		}
		total+=counter;
		cout<<"Case #"<<t<<": "<<total<<endl;
	}
}

return 0;
}