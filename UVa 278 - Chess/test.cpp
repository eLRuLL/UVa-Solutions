#include <stdio.h>
int main(){
	int cases,i,m,n;
	char piece;
	scanf("%d\n",&cases);
	for(i=0;i<cases;i++){
		scanf("%c %d %d",&piece,&m,&n);
		printf("%c %d %d\n",piece,m,n);
	}
	return 0;
}