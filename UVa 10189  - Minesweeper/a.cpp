#include <stdio.h>
#include <iostream>
#include <string>
#define VALID(x,y,h,w)	(x>=0 && y>=0 && x<h && y<w)
using namespace std;
int main(){
	int n,m,i,j,value,field=1;
	int** board;
	char** cboard;
	string line;
	cin>>n;
	cin>>m;
	bool flag = false;
	while(n!=0 || m!=0){
		if(flag){
			printf("\n");
		}

		board = new int*[n];
		cboard = new char*[n];
		for(i=0;i<n;i++){
			cin>>line;
			
			board[i] = new int[m];
			cboard[i] = new char[m];
			for(j=0;j<m;j++){
				if(line[j] == '*')
					board[i][j] = -1;
				else{
					board[i][j] = 0;
				}
				cboard[i][j] = line[j];
			}
		}

		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(cboard[i][j]!='*'){
					if(VALID(i-1,j-1,n,m)){
						if(cboard[i-1][j-1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i-1,j,n,m)){
						if(cboard[i-1][j] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i-1,j+1,n,m)){
						if(cboard[i-1][j+1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i,j-1,n,m)){
						if(cboard[i][j-1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i,j+1,n,m)){
						if(cboard[i][j+1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i+1,j-1,n,m)){
						if(cboard[i+1][j-1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i+1,j,n,m)){
						if(cboard[i+1][j] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i+1,j+1,n,m)){
						if(cboard[i+1][j+1] == '*'){
							board[i][j]++;
						}
					}
				}
			}
		}
		printf("Field #%d:\n",field);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(board[i][j] == -1)
					printf("*");
				else
					printf("%d",board[i][j]);
			}
			printf("\n");
		}
		for(i=0;i!=n;++i){
			delete[] board[i];
			delete[] cboard[i];
		}

		delete[] board;
		delete[] cboard;
		cin>>n;
		
		cin>>m;
		
		
		flag = true;
		field++;
	}
	//cout<<"cosas de la vida"<<endl;
	return 0;
}