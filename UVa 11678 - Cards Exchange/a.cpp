#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	
	int A,B,i,counter,temp,size;
	set<int> valuesA,valuesB;
	set<int>::iterator it;
	while(true){
		counter = 0;
		scanf("%d %d",&A,&B);
		if(A==0 && B==0){
			break;
		}else{
			for(i=0;i<A;i++){
				scanf("%d",&temp);
				//printf("- %d\n",temp);
				valuesA.insert(temp);
			}

			size = valuesA.size();

			for(i=0;i<B;i++){
				scanf("%d",&temp);
				valuesB.insert(temp);
			}
			if(valuesA.size()>valuesB.size()){
				for(it=valuesB.begin(); it!=valuesB.end(); it++){
					
					if(valuesA.find(*it)==valuesA.end())
						counter++;
				}
			}else{
				for(it=valuesA.begin(); it!=valuesA.end(); it++){
					
					if(valuesB.find(*it)==valuesB.end())
						counter++;
				}
			}
			//printf("%d %d\n",counter,size);
			printf("%d\n",counter);
			valuesA.clear();
			valuesB.clear();
		}
	}
	return 0;
}