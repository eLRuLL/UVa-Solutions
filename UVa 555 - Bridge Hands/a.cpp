#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


map<char,int> suit;


map<char,int> deck;




bool myfunction (string i,string j) {
	if(suit[i[0]] == suit[j[0]]){
		return (deck[i[1]] < deck[j[1]]);
	}else{
		return (suit[i[0]] < suit[j[0]]);
	}
}

int main(){
	suit['C'] = 0;
	suit['D'] = 1;
	suit['S'] = 2;
	suit['H'] = 3;
	
	deck['2'] = 2;
	deck['3'] = 3;
	deck['4'] = 4;
	deck['5'] = 5;
	deck['6'] = 6;
	deck['7'] = 7;
	deck['8'] = 8;
	deck['9'] = 9;
	deck['T'] = 10;
	deck['J'] = 11;
	deck['Q'] = 12;
	deck['K'] = 13;
	deck['A'] = 14;


	int i,j,current;
	char c;
	string dump;
	string cards,buffer;
	vector<string> players[4];
	vector<string>::iterator pl_it;
	map<char,int> dir;
	map<int,char> rdir;
	
	dir['S'] = 0;
	dir['W'] = 1;
	dir['N'] = 2;
	dir['E'] = 3;
	rdir[0] = 'S';
	rdir[1] = 'W';
	rdir[2] = 'N';
	rdir[3] = 'E';


	while(cin>>c){
		if(c=='#'){
			return 0;
		}else{
			current = (dir[c]+1)%4;

			cin>>cards;
			cin>>buffer;
			cards += buffer;

			for(i=0;i<13;i++){
				for(j=0;j<4;j++){
					
					dump = cards.substr((i*4 +j)*2,2);
					//cout<<dump;
					players[current].push_back(dump);
					current = (current + 1)%4;
				}
			}
			for(i=0;i<4;i++){
				sort(players[i].begin(),players[i].end(),myfunction);
				printf("%c:",rdir[i]);
				for(pl_it=players[i].begin();pl_it!=players[i].end(); pl_it++){
					cout<<" "<<(*pl_it);
				}
				printf("\n");
				players[i].clear();
			}
		}
	}
	return 0;
}