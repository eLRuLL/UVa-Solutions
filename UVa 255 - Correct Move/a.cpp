#include <stdio.h>
#include <stdlib.h>

bool between(int first,int last, int v){
	return (first < last ? v >= first && v <= last : v >= last && v <= first);
}

int main(){
	int p1,p2,pn,kx,ky,qx,qy,nx,ny;
	while(scanf("%d %d %d",&p1,&p2,&pn)!=EOF){
		kx = p1/8;
		ky = p1%8;

		qx = p2/8;
		qy = p2%8;

		nx = pn/8;
		ny = pn%8;

		//printf("kx=%d ky=%d , qx=%d qy=%d , nx=%d ny=%d\n",kx,ky,qx,qy,nx,ny);
		if(p1==p2){
			printf("Illegal state\n");
		}else if(qx != nx && qy != ny){
			printf("Illegal move\n");
		}else if(p2 == pn){
			printf("Illegal move\n");
		}else{
			if( (nx == qx && kx == nx && between(qy,ny,ky)) || (ny == qy && ky == ny && between(qx,nx,kx)) ) {
				printf("Illegal move\n");
			}else if((kx==nx && abs(ky-ny)==1) || (ky==ny && abs(kx-nx)==1 ) ) {
				printf("Move not allowed\n");
			}else if((p1==0 && pn==9) || (p1==7 && pn==14) || (p1==56 && pn==49) || (p1==63 && pn==54)){
				printf("Stop\n");
			}else{
				printf("Continue\n");
			}
		} 
	}
	return 0;
}