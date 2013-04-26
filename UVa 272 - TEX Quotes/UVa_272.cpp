#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	std::string linebuf;
	char* token, * str_cha;
	int sum,i,size;
	
	while(getline(std::cin,linebuf)){
		
		sum = 0;
		size = linebuf.size();
		i=0;
		while(i<size){
			if((linebuf[i]>='A' && linebuf[i]<='Z') || (linebuf[i]>='a' && linebuf[i]<='z')){
				sum += 1;
				while( (linebuf[i]>='A' && linebuf[i]<='Z') || (linebuf[i]>='a' && linebuf[i]<='z') ){
					i++;
				}
			}else{
				i++;
			}
		}

		printf("%d\n",sum);
	}
	return 0;
}