#include <stdio.h>

using namespace std;

int main(){
	unsigned int t, test,f,yard,anim,fri, budget;
	scanf("%d",&t);
	test = t;
	while(t--){
		budget = 0;
		scanf("%d",&f);
		while(f--){

			scanf("%d %d %d",&yard,&anim,&fri);
			budget += yard*fri;
		}

		printf("%d\n",budget);
	}
	return 0;
}