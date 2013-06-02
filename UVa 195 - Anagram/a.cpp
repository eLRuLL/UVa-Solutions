#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool compare(char a,char b){
	bool a_up=false,b_up=false;
	a_up = (a>='A' && a<='Z');
	b_up = (b>='A' && b<='Z');
	if(!a_up && !b_up)
		return a<b;
	if(a_up && b_up)
		return a<b;
	if(a_up){
		a = tolower(a);
		if(a==b){
			return true;
		}else{
			a<b;
		}
	}else{
		b = tolower(b);
		if(a==b){
			false;
		}else{
			return a<b;
		}
	}
}

int main(){
	int t;
	cin>>t;
	string str;
	while(t--){
		cin>>str;
		sort(str.begin(),str.end(),compare);
		do{
			cout<<str<<endl;
		}while(next_permutation(str.begin(),str.end()));
	}
	return 0;
}