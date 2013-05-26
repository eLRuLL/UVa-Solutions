#include <stdio.h>
#include <stdlib.h>
#define max(x,y)	(x>y)?x:y
#define VALID(x)	(x>=0 && x<8)

bool board[8][8];
char cboard[8][8];

void rook(int x,int y){
	int k = x;
	int l = y-1;
	while(l>=0){ // left
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			l--;
		}else{
			break;
		}
	}
	
	k = x;
	l = y+1;
	while(l<8){ // right
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			l++;
		}else{
			break;
		}
	}

	k = x -1;
	l = y;
	while(k>=0){ // up
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			k--;
		}else{
			break;
		}
	}

	k = x + 1;
	l = y;
	while(k<8){ // down
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			k++;
		}else{
			break;
		}
	}
}

void knight(int x, int y){
	if( VALID(x-1) && VALID(y-2) )
		board[x-1][y-2] = false;
	if( VALID(x-1) && VALID(y+2) )
		board[x-1][y+2] = false;
	if( VALID(x+1) && VALID(y-2) )
		board[x+1][y-2] = false;
	if( VALID(x+1) && VALID(y+2) )
		board[x+1][y+2] = false;
	if( VALID(x-2) && VALID(y-1) )
		board[x-2][y-1] = false;
	if( VALID(x-2) && VALID(y+1) )
		board[x-2][y+1] = false;
	if( VALID(x+2) && VALID(y-1) )
		board[x+2][y-1] = false;
	if( VALID(x+2) && VALID(y+1) )
		board[x+2][y+1] = false;
}

void bishop(int x,int y){
	int k = x-1;
	int l = y-1;
	while(k>=0 && l>=0){ // Upper-left
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			k--;
			l--;
		}else{
			break;
		}
	}

	k = x-1;
	l = y+1;
	while(k>=0 && l<8){ // Upper-right
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			k--;
			l++;
		}else{
			break;
		}
	}

	k = x+1;
	l = y-1;
	while(k<8 && l>=0){ // Down-left
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			k++;
			l--;
		}else{
			break;
		}
	}

	k = x+1;
	l = y+1;
	while(k<8 && l<8){ // Down-right
		if(cboard[k][l] == '.'){
			board[k][l] = false;
			k++;
			l++;
		}else{
			break;
		}
	}
}

void queen(int x,int y){
	rook(x,y);
	bishop(x,y);
}

void king(int x,int y){
	if(VALID(x-1) && VALID(y-1))
		board[x-1][y-1] = false;
	if(VALID(x-1) && VALID(y))
		board[x-1][y] = false;
	if(VALID(x-1) && VALID(y+1))
		board[x-1][y+1] = false;
	if(VALID(x) && VALID(y-1))
		board[x][y-1] = false;
	if(VALID(x) && VALID(y+1))
		board[x][y+1] = false;
	if(VALID(x+1) && VALID(y-1))
		board[x+1][y-1] = false;
	if(VALID(x+1) && VALID(y))
		board[x+1][y] = false;
	if(VALID(x+1) && VALID(y+1))
		board[x+1][y+1] = false;
}

void pawn(int x,int y, bool color){
	// true for black
	// false for white
	if(color){
		if(VALID(x+1) && VALID(y-1))
			board[x+1][y-1] = false;
		if(VALID(x+1) && VALID(y+1))
			board[x+1][y+1] = false;
	}else{
		if(VALID(x-1) && VALID(y-1))
			board[x-1][y-1] = false;
		if(VALID(x-1) && VALID(y+1))
			board[x-1][y+1] = false;
	}
}

bool isNumber(char c){
	return (c>='0' && c<='9');
}
int main(){
	char buffer[1024];
	int k,i,j, res,it;
	while(scanf("%s",buffer)!= EOF){
		res = 0;
		k=0;
		i=0;
		j=0;
		while(buffer[k]){
			if(isNumber(buffer[k])){
				
				for(it=0;it<buffer[k]-'0';it++){
					cboard[i][j] = '.';
					board[i][j] = true;
					j++;
				}
			}else if(buffer[k]=='/'){
				i++;
				j=0;
			}else{
				cboard[i][j] = buffer[k];
				board[i][j] = false;
				j++;
			}
			k++;
		}
		
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(cboard[i][j]=='r' || cboard[i][j]=='R'){
					rook(i,j);
				}else if(cboard[i][j]=='n' || cboard[i][j]=='N'){
					knight(i,j);
				}else if(cboard[i][j]=='b' || cboard[i][j]=='B'){
					bishop(i,j);
				}else if(cboard[i][j]=='q' || cboard[i][j]=='Q'){
					queen(i,j);
				}else if(cboard[i][j]=='k' || cboard[i][j]=='K'){
					king(i,j);
				}else if(cboard[i][j]=='p'){
					pawn(i,j,true);
				}else if(cboard[i][j]=='P'){
					pawn(i,j,false);
				}
			}
		}
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(board[i][j])
					res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}