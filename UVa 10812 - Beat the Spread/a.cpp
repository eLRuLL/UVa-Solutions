#include <stdio.h>
#include <math.h>

int main(){
	int t,i,s,d;
	float a,b;
	scanf("%d",&t);

	for(i=0;i<t;i++){
		scanf("%d %d",&s,&d);
		a = (s+d)/2.0;
		if(a!=floor(a)){
			printf("impossible\n");
			continue;
		}
		b = s - a;
		if(b<0){
			printf("impossible\n");
		}else{
			if(a>b){
				printf("%d %d\n",(int)a,(int)b);
			}else{
				printf("%d %d\n",(int)b,(int)a);
			}
		}
	}

	return 0;
}