#include <stdio.h>
#include <string.h>

// Every case is only of ten digits, so it doesn't matter which kind of check
// you do.

int main(){
	int N,i,lum[10];
	bool asc,flag;
	scanf("%d",&N);
	printf("%s\n","Lumberjacks:");
	while(N--){
		flag = true;
		for(i=0;i<10;i++){
			scanf("%d",&lum[i]);
		}
		
		
		if(lum[1]-lum[0] > 0){
			asc = true;
		}else{
			asc = false;
		}
		for(i=2;i<10;i++){
			if(asc){
				
				if(lum[i] < lum[i-1]){
					printf("%s\n","Unordered");
					flag = false;
					break;
				}
			}else{
				if(lum[i] > lum[i-1]){
					printf("%s\n","Unordered");
					flag = false;
					break;
				}
			}
		}
		if(flag)
			printf("%s\n","Ordered");
	}
	return 0;
}