#include <stdio.h>

int main(){
	int T,i,h,l,w,j,cu;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		l=0;
		h=0;
		scanf("%d",&w);
		
		scanf("%d",&cu);
		
		while(--w){

			scanf("%d",&j);
			
			if(j<cu){
				l++;
			}else if(j>cu){
				h++;
			}
			
			cu=j;

		}
		printf("Case %d: %d %d\n",i,h,l);
	}
	return 0;
}