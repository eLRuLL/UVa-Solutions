#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	int t,hojas,paginas,i,back,j;
	bool flag;
	scanf("%d",&t);
	while(t!=0){
		if(t==1)
		{
			printf("Printing order for 1 pages:\n");
			printf("Sheet 1, front: Blank, 1\n");
			scanf("%d",&t);
		}else{

			hojas = ceil(t/4.0);
			paginas = hojas*4;

			i=1;
			back = paginas;
			//printf("paginas = %d\n",paginas);

			printf("Printing order for %d pages:\n",t);
			for(j=1;j<=hojas;j++){
				// imprimir adelante
				printf("Sheet %d, front: ",j);
				if(paginas>t){
					printf("Blank, ");
				}else{
					printf("%d, ",paginas);
				}
				printf("%d\n",i);
				paginas--;
				i++;
				

				// imprimir atras
				printf("Sheet %d, back : ",j);
				printf("%d, ",i);
				if(paginas>t){
					printf("Blank\n");
				}else{
					printf("%d\n",paginas);
				}
				paginas--;
				i++;
			}
			scanf("%d",&t);
		}
	}
	return 0;
}