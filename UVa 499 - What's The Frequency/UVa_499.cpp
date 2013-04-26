#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	string linebuf;

	map<char,int> upper;
	map<char,int> lower;

	map<char,int>::iterator it;

	int i,size,maxi;
	while(getline(cin,linebuf)){
		maxi = 0;
		size = linebuf.size();

		for(i=0;i<size;i++){
			if( linebuf[i]>='A' && linebuf[i]<='Z'){
				upper[linebuf[i]]++;
				maxi = max(maxi,upper[linebuf[i]]);
			}else if( linebuf[i]>='a' && linebuf[i]<='z' ){
				lower[linebuf[i]]++;
				maxi = max(maxi,lower[linebuf[i]]);
			}
		}

		
		for(it=upper.begin();it!=upper.end();it++){
			if(it->second == maxi){
				printf("%c",it->first);
			}
		}
		for(it=lower.begin();it!=lower.end();it++){
			if(it->second == maxi){
				printf("%c",it->first);
			}
		}
		
		printf(" %d\n",maxi);

		upper.clear();
		lower.clear();
	}

	return 0;
}