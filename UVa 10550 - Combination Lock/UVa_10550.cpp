#include <stdio.h>

int main(){
	int pos,l1,l2,l3,total;
	while(scanf("%d %d %d %d",&pos,&l1,&l2,&l3) != EOF){

		total = 0;
		if(pos + l1 + l2 + l3){
			total += 80;
			total += (40 - (l1 - pos))%40;

			total += 40;

			total += (40 + (l2 - l1))%40;
			total += (40 - (l3 - l2))%40;

			printf("%d\n",total*9);
		}else{
			break;
		}
	}
	return 0;
}