#include <iostream>
#include <vector>

using namespace std;

static vector<int> months(12);
	

class MyDate{
public:

	int day;
	int month;
	int year;

	MyDate(){
		day = month = year = 0;
	}
	MyDate(int d, int m, int y){
		day = d;
		month = m;
		year = y;
	}

	bool isLeap(){
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

	void add(int n){
		for(int i=0; i < n; i++){
			plusOne();
		}
	}

	void plusOne(){
		if( month == 12 && day == 31){
			day = 1;
			month = 1;
			year++;
		}else if(month != 2){
			if(day == months[month-1]){
				day = 1;
				month++;
			}else{
				day++;
			}
		}else if(isLeap()) {
			if(day == 29){
				day = 1;
				month ++;
			}else{
				day++;
			}
		}else{
			if(day == 28){
				day = 1;
				month++;
			}else{
				day++;
			}
		}
	}
	void print(){
		cout<<day<<" "<<month<<" "<<year<<endl;
	}
};

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
	


	int n1,n2,n3,n4;
	while(true){

		cin>>n1>>n2>>n3>>n4;
		if(n1==0 && n2==n1 && n3==n2 && n4==n3){
			break;
		}
		MyDate data(n2, n3, n4);
		data.add(n1);
		data.print();
	}
	
	return 0;
}