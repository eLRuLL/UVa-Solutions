#include <iostream>
#include <vector>

using namespace std;


vector<int> months(12);



bool isLeap(int year){
	if (year % 400 == 0){
		return true;
	}else{
		if(year % 4 == 0){
			if(year % 100 != 0){
				return true;
			}
		}
		return false;
	}
}

int daysToMonth(int dd, int mm, int yy){
	if(mm == 2 && isLeap(yy)){
		return 29 - dd;
	}else{
		return months[mm-1] - dd;
	}
}

int daysToYear(int dd, int mm, int yy){
	int rpta = 0;
	if(mm <= 2 && isLeap(yy)){
		rpta++;
	}

	for(int i=mm; i<12 ; i++){
		rpta += months[i];
	}

	return rpta + daysToMonth(dd,mm,yy);
}


void increaseMonth(int &mm, int &yy){
	if(mm == 12){
		mm = 1;
		yy++;
	}else{
		mm++;
	}	
}

void increaseDay(int &days, int &mm, int &yy){
	if( mm==2 && isLeap(yy) ){
		if( (days) > 29 ){
			mm++;
			days = days - 29;
		}
	}else{
		if( (days) > months[mm-1] ){
			mm++;
			days = days - months[mm-1];
		}
	}
}

int main(){

	
	months[0] = 31;
	months[1] = 28;
	months[2] = 31;
	months[3] = 30;
	months[4] = 31;
	months[5] = 30;
	months[6] = 31;
	months[7] = 31;
	months[8] = 30;
	months[9] = 31;
	months[10] = 30;
	months[11] = 31;


	int n1,dd,mm,yy;
	int tempmm;

	int years, days, leaps;
	int temp4,temp100,temp400;
	int counter, newyy;
	while(true){
		cout<<"#######################################################"<<endl;

		days = 0;
		years = 0;

		cin>>n1>>dd>>mm>>yy;
		if(n1==0 && dd==n1 && mm==dd && yy==mm){
			break;
		}

		//cout<<"days to Month: "<< daysToMonth(dd,mm,yy) << endl;

		while( n1 != 0 )
		{
			years += n1 / 365;
		
			temp4 = ( (yy+years) / 4 ) - ( yy / 4 );
			temp100 = ( (yy+years) / 100 ) - ( yy / 100 );
			temp400 = ( (yy+years) / 400 ) - ( yy / 400 );

			leaps = temp4 - temp100 + temp400;
			days = n1 % 365;


			n1 = leaps/365;
		}
	

		newyy = yy+years;
		
		
		cout<<"extra days: "<<days<<endl;
		cout<<"daysToYear(dd, mm, newyy): "<<daysToYear(dd, mm, newyy)<<endl;
		if( days > daysToYear(dd, mm, newyy)){
			newyy++;
			days = days - daysToYear(dd,mm,newyy);
			dd = 1;
			mm = 1;
		}

		if( days <= daysToMonth(dd,mm,newyy) ){
			cout<<days<<" "<<mm<<" "<<newyy<<endl;
			continue;
		}
		cout<<"days: "<<days<<endl;
		tempmm = mm;
		days = days - daysToMonth(dd, mm, newyy);
		cout<<"days - daysToMonth(dd, mm, newyy): "<< days<<endl;
		increaseMonth(mm,newyy);
		cout<<"increaseMonth(mm,newyy): "<<mm<<" "<<newyy<<endl;
		while(days > months[tempmm-1]){
			cout<<"months[tempmm-1]: "<<months[tempmm-1]<<endl;
			days = days - months[tempmm-1];
			tempmm++;
			mm++;
		}
		increaseDay(days,mm,newyy);
		cout<<"increaseDay(days,dd,mm,newyy): "<<days<<endl;
		cout<<days<<" "<< mm <<" " << newyy<<endl;
	}
	
	return 0;
}