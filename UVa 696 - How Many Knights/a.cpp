#include <stdio.h>
#define max(x,y)	(x>y)?x:y
#define min(x,y)	(x<y)?x:y

int main(){
	int m,n,res;
	scanf("%d %d",&m,&n);
	while(m!=0 || n!=0){
		if(m==1 || n==1){
			res = max(m,n);
		}else if(m==2 || n==2){
			res = (min((max(m,n)%4),2))*2 + (max(m,n)/4)*4;
		}else{
			res = (m*n+1)>>1;
		}
		printf("%d knights may be placed on a %d row %d column board.\n",res,m,n);
		scanf("%d %d",&m,&n);
	}
	return 0;
}