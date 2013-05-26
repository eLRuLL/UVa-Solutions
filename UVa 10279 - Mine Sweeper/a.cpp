#include <stdio.h>
#include <vector>
#include <iostream>
#define VALID(x,y,h,w)	(x>=0 && y>=0 && x<h && y<w)

using namespace std;

int main(){
	int cases,i,j,n,c;
	string line;
	vector<string> cboard;
	vector<string> touched;
	int** board;
	bool flag=false;
	bool flag_mine;
	cin>>cases;
	for(c=0;c<cases;c++){
		flag_mine = false;
		if(flag){
			printf("\n");
		}
		cin>>n;
		board = new int*[n];
		for(j=0;j<n;j++){
			
			board[j] = new int[n];
			cin>>line;
			cboard.push_back(line);
			for(i=0;i<n;i++){
				board[j][i] = 0;
			}
		}
		for(j=0;j<n;j++){
			cin>>line;
			touched.push_back(line);
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(touched[i][j] == 'x'){
					if(cboard[i][j] == '*'){
						flag_mine = true;
					}
					if(VALID(i-1,j-1,n,n)){
						if(cboard[i-1][j-1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i-1,j,n,n)){
						if(cboard[i-1][j] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i-1,j+1,n,n)){
						if(cboard[i-1][j+1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i,j-1,n,n)){
						if(cboard[i][j-1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i,j+1,n,n)){
						if(cboard[i][j+1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i+1,j-1,n,n)){
						if(cboard[i+1][j-1] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i+1,j,n,n)){
						if(cboard[i+1][j] == '*'){
							board[i][j]++;
						}
					}
					if(VALID(i+1,j+1,n,n)){
						if(cboard[i+1][j+1] == '*'){
							board[i][j]++;
						}
					}
				}
			}
		}
		if(flag_mine){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(cboard[i][j] == '*'){
						printf("*");
					}else if(touched[i][j] == 'x'){
						printf("%d",board[i][j]);
					}else{
						printf(".");
					}
				}
				printf("\n");
			}
		}else{
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(touched[i][j] == 'x'){
						printf("%d",board[i][j]);
					}else{
						printf(".");
					}
				}
				printf("\n");
			}
		}
		
		//printf("\n");

		for(j=0;j<n;j++){
			delete[] board[j];
		}
		delete[] board;
		cboard.clear();
		touched.clear();
		flag = true;
	}
	return 0;
}