#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int t;
	string line;
	scanf("%d",&t);
	map<string,int> love;
	map<string,int>::iterator it;
	getline(cin,line);
	while(t--){
		getline(cin,line);
		love[line.substr(0, line.find(" "))]++;
	}
	for(it=love.begin(); it != love.end(); it++){
		printf("%s %d\n",it->first.c_str(),it->second);
	}
	return 0;
}