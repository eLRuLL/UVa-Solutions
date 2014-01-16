#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int N,i;
	string date,MM,DD,YYYY;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		cin>>date;
		MM=date.substr(0,2);
		DD=date.substr(2,2);
		YYYY=date.substr(4,4);
		printf("%d %s/%s/%s",i,MM.c_str(),DD.c_str(),YYYY.c_str());
	}
	return 0;
}