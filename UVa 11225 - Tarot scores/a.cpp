#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
int main(){
	int T,i,j,c,M,x, goal;
	float points;

	string line,first,temp;
	//stringstream ss;
	bool flag=false;
	cin>>T;
	for(c=1;c<=T;c++){

		
		x=0;
		points = 0;
		
		if(flag)
			printf("\n");
		
		cin>>temp;
		
		getline(cin,line);

		//printf("%s\n",temp.c_str());
		for(i=0;i<atoi(temp.c_str());i++){
			getline(cin,line);	
			
			stringstream ss(line);
			
			ss>>first;
			//cout<<first<<endl;
			//ss>>line;
			
			if(first == "fool" || first == "twenty-one" || first == "one"){
				x += 1;
				points += 4.5;
			}else if(first == "king"){
				points += 4.5;
			}else if(first == "queen"){
				points += 3.5;
			}else if(first == "knight"){
				points += 2.5;
			}else if(first == "jack"){
				points += 1.5;
			}else{
				points += 0.5;
			}
		}

		switch(x){
			case 0: goal = 56; break;
			case 1: goal = 51; break;
			case 2: goal = 41; break;
			case 3: goal = 36; break;
		}

		printf("Hand #%d\n",c);
		//printf("points:%g goal:%d x:%d\n",points,goal,x);
		if(points >= goal)
			printf("Game won by %g point(s).\n",points - goal);
		else
			printf("Game lost by %g point(s).\n",goal - points);
		flag = true;		
	}
	return 0;
}