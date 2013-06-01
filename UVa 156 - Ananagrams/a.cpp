#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(){
	string str,tmp;
	map<string,string> ananagrams;
	set<string> ananagrams_v;
	ananagrams_v.insert("#");
	cin>>str;
	while(str.compare("#")!=0){
		tmp = str;
		transform(tmp.begin(),tmp.end(), tmp.begin(),::tolower);
		sort(tmp.begin(),tmp.end());
		//cout<<tmp<<endl;
		if(ananagrams_v.find(tmp)==ananagrams_v.end()){
			ananagrams_v.insert(tmp);
			ananagrams.insert(pair<string,string>(tmp,str));
		}else{
			ananagrams.erase(tmp);
		}
		cin>>str;
	}

	map<string,string>::iterator it;
	//cout<<ananagrams.size()<<endl;
	//cout<<ananagrams_v.size()<<endl;
	ananagrams_v.clear();
	for(it=ananagrams.begin();it!=ananagrams.end();it++)
		ananagrams_v.insert(it->second);
	set<string>::iterator it2;
	for(it2=ananagrams_v.begin();it2!=ananagrams_v.end();it2++)
		cout<<*it2<<endl;
	return 0;
}