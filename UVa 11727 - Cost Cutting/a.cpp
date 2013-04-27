#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;
int main(){
	int T,i,p1,p2,p3;
	vector<int> values;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d %d %d",&p1,&p2,&p3);
		values.push_back(p1);
		values.push_back(p2);
		values.push_back(p3);
		sort(values.begin(), values.end());
		printf("Case %d: %d\n",i,values[1]);
		values.clear();
	}
	return 0;
}