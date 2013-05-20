#include <iostream>
#include <sstream>

using namespace std;
int main(){
	stringstream ss;
	string buffer,first_word;
	int i;
	for(i = 0; i < 4; i++){
		getline(cin,buffer);	// getting line
		ss.str(buffer);			// initializing the stream
		ss>>first_word;
		cout<<first_word<<endl;
		ss.str("");		// cleaning stream
		ss.clear();
	}
	return 0;
}