#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	double H, M;
	double angM, angH;
	double greater;
	int i;
	double angle;
	string line,tmp;
	cin>>line;
	while(line != "0:00"){
		i=0;
		tmp = line.substr(0,line.find(":"));
		H = atoi(tmp.c_str());
		tmp = line.substr(line.find(":")+1,line.size()+1);
		M = atoi(tmp.c_str());
		
		angM = M*6;
		angH = H*30 + 30/(60.0/M);

		if(angM > angH){
			angle = angM - angH;
		}else{
			angle = angH - angM;
		}

		if(angle>180){
			printf("%0.3f\n",360-angle);
		}else{
			printf("%0.3f\n",angle);
		}

		
		cin>>line;
	}
	return 0;
}