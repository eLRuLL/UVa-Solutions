#include <stdio.h>
#include <algorithm>


using namespace std;

int main(){
	int N,B,H,W,i,p,j,a,price,beds,res;
	while(scanf("%d %d %d %d",&N,&B,&H,&W) != EOF){
		res = 500001;
		for(i=0;i<H;i++){
			
			scanf("%d",&p);

			for(j=0;j<W;j++){
				scanf("%d",&a);
				if(a >= N && p*N <=B){
					res = min(res,p*N);
				}
			}
		}
		if(res>= 500001){
			printf("%s\n","stay home");
		}else{
			printf("%d\n",res);
		}
	}
	
	return 0;
}