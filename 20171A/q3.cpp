#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int main() {
	string input;
	getline(cin, input);
	int T=stoi(input);

	ll Hd, Ad, Hk, Ak, B, D;

	ll Dttk, Kttk;
	ll pDttk, pKttk;
	ll counter;
	ll tempAtk;

	ll rawHeal;
	ll rawDeb;

for (int t=0; t<T; t++) {
	cout<<"Case #"<<t+1<<": ";
	getline(cin, input, ' ');
	Hd=stoi(input);
	getline(cin, input, ' ');
	Ad=stoi(input);
	getline(cin, input, ' ');
	Hk=stoi(input);
	getline(cin, input, ' ');
	Ak=stoi(input);
	getline(cin, input, ' ');
	B=stoi(input);
	getline(cin, input);
	D=stoi(input);

	//calculate raw Dttk;
	if (Hk%Ad==0) {Dttk=Hk/Ad;}
	else {Dttk=(Hk+1)/Ad;}
	//cout<<"raw dragon ttk is: "<<Dttk<<endl;

	//cout<<"finding min Kttk: ";
	//calculate raw Kttk;
	if (Hd%Ak==0) {Kttk=Hd/Ak;}
	else {Kttk=(Hd+1)/Ak;}
	//cout<<Kttk<<endl;

	//min found if dttk is already less - attack phase minimised
	if (Dttk<=Kttk) {
		cout<<Dttk<<endl;
		continue;
	} else if (Kttk==1) {
		cout<<"IMPOSSIBLE"<<endl;
		continue;
	}

if (B!=0) {
	counter=0;
	ll lowest = Dttk;
	ll tAd=Ad;
	//cout<<"current attack: "<<tAd<<endl;
	//cout<<"finding min Dttk: ";
	do {
		//attack damage of dragon increased
		tAd +=B; counter++;
		//calculate time for dragon to kill with increased damage
		if (Hk%tAd==0) {pDttk=Hk/tAd;}
		else {pDttk=(Hk+1)/tAd;}
		//compare raw ttk to buffed ttk + #turns for buffing
		//if buffing results in a faster ttk, keep going
		if (pDttk+counter<lowest) {lowest=pDttk+counter;}
		else {break;}
	} while (true);
	Dttk=lowest;
	//cout<<Dttk<<endl;

	//min found if dttk is already less - attack phase minimised
	if (Dttk<=Kttk) {
		cout<<Dttk<<endl;
		continue;
	} 
}

	//else, find #turns of defensive moves needed to raise Kttk
	//if debuff makes knight atk go to 0, increase min by 1
	//else find min debuffs + heals if necessary to do it
	ll tHd = Hd;
	ll tAk = Ak;
	counter=0;
	//cout<<"finding min defensive moves"<<endl;
	rawDeb=9999999;
	if (D>Ak) {
		cout<<Dttk+1<<endl; continue;
	} else if (D!=0) {
		do {
			//for every debuff applied
			//calculate the new ttk
			counter++;
			tAk-=D;
			if (tAk==0) {break;}
			//if health will fall below 0 we need a turn for a heal
			if (tHd-tAk > 0) {tHd-=tAk;} else {tAk+=D;}
			if (Hd%tAk==0) {pKttk=Hd/tAk;}
			else {pKttk=(Hd+1)/tAk;}
			//cout<<"Dttk is: "<<Dttk<<" pKttk is: "<<pKttk<<endl;
			//repeat while knight still kills faster
		} while ((pKttk<Dttk)&&(tAk>0));
		rawDeb = Dttk+counter; //our ttk + turns for defense
	}

	//cout<<"rawDeb is: "<<rawDeb<<endl;

	//if base attack can two shot us, heals are not viable
	//healamt is minus remainer of ak and ak of next attack
	ll healAmt = Hd-(Hd%Ak)-Ak;
	//cout<<"healAmt is: "<<healAmt<<endl;
	tHd = Hd;
	tAk = Ak;
	counter=0;
	//cout<<"finding min heal moves"<<endl;
	if (2*Ak>Hd) {
		if (rawDeb!=9999999) {cout<<rawDeb<<endl; continue;} 
		else {cout<<"IMPOSSIBLE"<<endl; continue;}
	} else {
		do {
			//increase dragon hp by that amount
			tHd+=healAmt; counter++;
			//find new time for knight to kill
			if (tHd%tAk==0) {pKttk=tHd/tAk;}
			else {pKttk=(tHd+1)/tAk;}
		} while (pKttk+counter<Dttk);
		rawHeal = Dttk+counter+1;
	}
	//cout<<"rawHeal is: "<<rawHeal<<endl;

	//cout<<"final statement"<<endl;
	cout<<min(rawDeb, rawHeal)<<endl;

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

