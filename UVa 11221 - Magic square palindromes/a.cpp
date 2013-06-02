#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool is_2transpose(vector<vector<char> >& m){
	int i,j,len;
	len = m.size();
	//cout<<"trans: "<<len<<endl;
	for(i=0;i<len;i++){
		//cout<<"i: "<<i<<endl;
		for(j=i;j<len;j++){
			//cout<<"j: "<<j<<endl;
			//printf(" (m[%d][%d] != m[%d][%d]) || (m[%d][%d] != m[%d][%d]) \n",i,j,j,i,i,len-j-1,j,len-i-1);
			if( (m[i][j] != m[j][i]) || (m[i][len-j-1] != m[j][len-i-1]) ){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int t,tt,i,j;
	cin>>t;
	string line; 
	string::iterator s_it;
	vector<char> v;
	vector<vector<char> > matrix;
	getline(cin,line);

	double root;

	for(tt=1;tt<=t;tt++){
		getline(cin,line);
		for(s_it=line.begin();s_it!=line.end();s_it++){
			if((*s_it)>='a' && (*s_it)<='z'){
				v.push_back(*s_it);
			}
		}
		printf("Case #%d:\n",tt);
		root = sqrt(v.size());
		//cout<<root<<endl;
		if( root == (int)(root) ){
			matrix.resize(root);
			for(i=0;i<root;i++){
				matrix[i].resize(root);
				for(j=0;j<root;j++){
					matrix[i][j]=v[i*root+j];
				}
			}
			//cout<<v.size()<<endl;
			if(is_2transpose(matrix)){
				printf("%d\n",(int)(root));
			}else{
				printf("No magic :(\n");
			}
			
			
		}else{
			printf("No magic :(\n");
		}
		v.clear();
	}
	return 0;
}