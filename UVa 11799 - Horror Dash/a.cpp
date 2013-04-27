#include <stdio.h>
#include <algorithm>

using namespace std;
int main(){
	int T,i,N,st,res;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		res = 0;
		scanf("%d",&N);
		while(N--){
			scanf("%d",&st);
			res = max(res,st);
		}
		printf("Case %d: %d\n",i,res);
	}
	return 0;
}