#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

int main(){

	map<char,int> cards;

	cards['2'] = 2;
	cards['3'] = 3;
	cards['4'] = 4;
	cards['5'] = 5;
	cards['6'] = 6;
	cards['7'] = 7;
	cards['8'] = 8;
	cards['9'] = 9;
	cards['T'] = 10;
	cards['J'] = 10;
	cards['Q'] = 10;
	cards['K'] = 10;
	cards['A'] = 10;

	int cases,i,j,y,x,top,k;
	string buffer;
	deque<string> deck;
	vector<string> hand;

	//vector<string>::reverse_iterator rit;
	//vector<string>::iterator it;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		for(j=0;j<52;j++){
			cin>>buffer;
			deck.push_back(buffer);
		}
		y = 0;
		
		hand.insert(hand.begin(),deck.begin()+27,deck.end());
		
		deck.erase(deck.begin()+27,deck.end());
		for(j=0;j<3;j++){
			
			x = cards[deck.back()[0]];
			y += x;
			
			deck.pop_back();
			deck.erase(deck.begin()+deck.size()-(10-x),deck.end());
		}
		deck.insert(deck.end(),hand.begin(),hand.end());
		printf("Case %d: %s\n",i,deck[y-1].c_str());
		deck.clear();
		hand.clear();
	}
	return 0;
}