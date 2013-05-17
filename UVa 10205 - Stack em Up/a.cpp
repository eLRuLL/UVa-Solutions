#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct card{
	string name;
	int value;
	string suit;

	card(string name,int value,string suit){
		this->name = name;
		this->value = value;
		this->suit = suit;
	}
	card(){};

	card& operator=(const card &new_card){
		this->name = new_card.name;
		this->value = new_card.value;
		this->suit = new_card.suit;
		return *this;
	}

	friend ostream& operator<<(ostream &out, card &new_card);
};

ostream& operator<<(ostream &out, card &new_card){
	out <<new_card.name << " of " << new_card.suit;
	return out;
}

int main(){
	int cases,n,i,j,temp;
	card tempcard;

	map<int,string> deck_names;
	deck_names[0] = "2";
	deck_names[1] = "3";
	deck_names[2] = "4";
	deck_names[3] = "5";
	deck_names[4] = "6";
	deck_names[5] = "7";
	deck_names[6] = "8";
	deck_names[7] = "9";
	deck_names[8] = "10";
	deck_names[9] = "Jack";
	deck_names[10] = "Queen";
	deck_names[11] = "King";
	deck_names[12] = "Ace";

	map<int,string> suits;
	suits[0] = "Clubs";
	suits[1] = "Diamonds";
	suits[2] = "Hearts";
	suits[3] = "Spades";

	vector<card> deck;

	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			deck.push_back(card(deck_names[j],(i*13)+j+1,suits[i]));
		}
	}

	

	vector<vector<int> > shuffles;
	vector<int> tempdeck,new_tempdeck;


	string line,obs;
	int obs_int;
	bool flag;
	cin>>cases;
	getline(cin,line);
	getline(cin,line);
	while(cases--){
		flag=false;
		tempdeck.resize(52);
		new_tempdeck.resize(52);
		for(i=0;i<52;i++){
			tempdeck[i] = i+1;
		}
		cin>>n;
		shuffles.resize(n);
		for(j=0;j<n;j++){
			for(i=0;i<52;i++){
				cin>>temp;
				shuffles[j].push_back(temp);
			}
		}
		
		getline(cin,obs);
		while(getline(cin,obs)){
			if(obs.empty()){
				flag=true;
				break;
			}
			obs_int = atoi(obs.c_str());
			for(i=0;i<52;i++){				
				new_tempdeck[i] = tempdeck[shuffles[obs_int-1][i]-1];
			}
			tempdeck = new_tempdeck;
		}
		for(i=0;i<4;i++){
			for(j=0;j<13;j++){
				cout<<deck[new_tempdeck[i*13+j]-1]<<endl;
			}
		}
		if(flag)
			cout<<endl;
		shuffles.clear();
		tempdeck.clear();
		new_tempdeck.clear();
	}
	return 0;
}