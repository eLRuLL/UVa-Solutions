#include <stdio.h>
#include <vector>

using namespace std;
int main(){
	int N,res,i,m,j;
	vector<bool> cities;
	scanf("%d",&N);
	while(N!=0){
		
		
			cities.assign(N,true);
			res = N-1;
			i=0;
			m=1;
			while(res!=0){
				if(i!=12){
					
					cities[i] = false;
					res--;
				
					j=0;
					//i = (i+1)%N;
					while(j<m){
						i = (i+1)%N;
						if(cities[i])
							j++;
						
					}
					
				}else{
					cities.clear();
					cities.assign(N,true);
					i=0;
					res = N-1;
					m++;
					//break;
				}				
			}
			printf("%d\n",m);
		
		scanf("%d",&N);
		cities.clear();
	}
	return 0;
}