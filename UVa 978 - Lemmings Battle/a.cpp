#include <iostream>
#include <set>
#include <vector>
#include <algorithm>



using namespace std;

typedef multiset<int, greater<int> >::iterator it_type;

int main(){
	int N,B,SG,SB;
	int i,temp;
	int actualB;
	multiset<int, greater<int> > SG_army;
	multiset<int, greater<int> > SB_army;
	it_type my_iterator;

	vector<int> fightersSG;
	vector<int> fightersSB;

	bool flag_first = false;

	cin>>N;
	while(N--){
		if(flag_first){
			cout<<endl;
		}
		cin>>B>>SG>>SB;

		for(i=0; i<SG; i++){
			cin>>temp;
			SG_army.insert(temp);
		}

		for(i=0; i<SB; i++){
			cin>>temp;
			SB_army.insert(temp);
		}

		while(!SG_army.empty() && !SB_army.empty()){
			actualB = min(B, min((int)SG_army.size(),(int)SB_army.size()));

			i=0;

			for(my_iterator = SG_army.begin(); i<actualB; i++){
				fightersSG.push_back(*my_iterator);
				SG_army.erase(my_iterator++);
			}

			i=0;
			for(my_iterator = SB_army.begin(); i<actualB; i++){
				fightersSB.push_back(*my_iterator);
				SB_army.erase(my_iterator++);
			}

			for(i=0;i<actualB;i++){
				if(fightersSB[i] >= fightersSG[i]){
					fightersSB[i] -= fightersSG[i];
					fightersSG[i] = 0;
				}else{
					fightersSG[i] -= fightersSB[i];
					fightersSB[i] = 0;
				}
			}

			for(i=0;i<actualB;i++){
				if(fightersSB[i]!=0){
					SB_army.insert(fightersSB[i]);
				}
				if(fightersSG[i]!=0){
					SG_army.insert(fightersSG[i]);
				}
			}

			fightersSG.clear();
			fightersSB.clear();
		}

		if(SG_army.empty() && SB_army.empty()){
			cout<<"green and blue died"<<endl;
		}else if(!SG_army.empty()){
			cout<<"green wins"<<endl;
			for(my_iterator = SG_army.begin(); my_iterator!= SG_army.end(); my_iterator++){
				cout<<*my_iterator<<endl;
			}
		}else{
			cout<<"blue wins"<<endl;
			for(my_iterator = SB_army.begin(); my_iterator!= SB_army.end(); my_iterator++){
				cout<<*my_iterator<<endl;
			}
		}
		flag_first = true;

		SG_army.clear();
		SB_army.clear();
	}
	return 0;
}