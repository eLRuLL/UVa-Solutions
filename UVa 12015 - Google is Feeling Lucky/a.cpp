#include <stdio.h>

#include <algorithm>
#include <string>

using namespace std;

int main(){
	int T,i,j,rank,maxim;
	string pages[10];

	int ranks[10];

	char name[1024];
	scanf("%d",&T);

	for(i=1;i<=T;i++){
		maxim = -1;

		printf("Case #%d:\n",i);

		for(j=0;j<10;j++){
			scanf("%s %d",name,&rank);
			
			ranks[j] = rank;
			
			pages[j] = name;

			maxim = max(rank,maxim);
		}
		
		for(j=0;j<10;j++){
			if(ranks[j] == maxim){
				printf("%s\n",pages[j].c_str());
			}
		}
	}

	return 0;
}