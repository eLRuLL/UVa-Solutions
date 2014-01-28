#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3




using namespace std;

typedef pair<int, int> my_key_type;
typedef map<my_key_type, int>          my_map_type;
typedef my_map_type::iterator it_type;

vector<vector<bool> > maze;
int maze_height, maze_width;
int direction;

my_map_type output;

string print_dir(int i){
	switch(direction){
		case NORTH: return "NORTH";
		case EAST: return "EAST";
		case WEST: return "WEST";
		case SOUTH: return "SOUTH";
		default: return "IMPOSSIBRUUU";
	}
}

bool wall_right(int x,int y){
	int newx = x;
	int newy = y;

	switch(direction){
		case NORTH: newy = y+1; break;
		case EAST: newx = x-1; break;
		case WEST: newx = x+1; break;
		case SOUTH: newy = y-1; break;
		default: cout<<"IMPOSSIBRUUU"<<endl; break;
	}

	if(newx < 0 || newy < 0){
		return true;
	}else if(newx >= maze_height || newy>= maze_width){
		return true;
	}else if(maze[newx][newy]){
		return true;
	}else{
		return false;
	}
}

bool wall_forward(int x, int y){
	int newx = x;
	int newy = y;

	//cout<<print_dir(direction)<<endl;
	switch(direction){
		case NORTH: newx = x+1; break;
		case EAST: newy = y+1; break;
		case WEST: newy = y-1; break;
		case SOUTH: newx = x-1; break;
		default: cout<<"IMPOSSIBRUUU"<<endl; break;
	}

	//cout<<newx<<" "<<newy<<endl;

	if(newx < 0 || newy < 0){
		return true;
	}else if(newx >= maze_height || newy>= maze_width){
		return true;
	}else if(maze[newx][newy]){
		return true;
	}else{
		return false;
	}
}

void move_forward(int& x, int& y){

	switch(direction){
		case NORTH: x = x+1; break;
		case EAST: y = y+1; break;
		case WEST: y = y-1; break;
		case SOUTH: x = x-1; break;
		default: cout<<"IMPOSSIBRUUU"<<endl; break;
	}
}




int main(){
	
	string maze_row;

	

	int i, j ;

	int position_x, position_y;
	
	while(true){

		position_x = position_y = 0;
		direction = EAST;

		cin>>maze_height;
		cin>>maze_width;
		
		if(maze_width == maze_height  && maze_width ==0){			
			break;
		}else{
			int solution[5] = {0,0,0,0,0};
			int wall_blocks=0;
			output.clear();
			maze.clear();
			maze.resize(maze_height);

			for( i=maze_height-1; i>=0; i-- ){
				maze[i].clear();
				maze[i].resize(maze_width);
				cin>>maze_row;

				for( j=0; j<maze_width; j++ ){
					maze[i][j] = maze_row[j] - '0';
					output.insert(my_map_type::value_type(my_key_type(i,j),0));
					wall_blocks += maze[i][j];
				}
			}

/*
			for(i=0;i<maze_height;i++){
				for(j=0;j<maze_width;j++){
					cout<<maze[i][j];
				}
				cout<<endl;
			}
*/
			bool just_change;
			do{
				just_change = false;
				//cout<<"->"<<"("<<position_x<<","<<position_y<<") -> "<<direction<<"="<<print_dir(direction)<<endl;
				if(!wall_right(position_x,position_y)){
					//cout<<"NO PARED A LA DERECHA"<<endl;
					direction = (direction+1)%4;
					move_forward(position_x, position_y);
					my_key_type my_key(position_x,position_y);
					output[my_key]++;
				}else if(wall_forward(position_x,position_y)){
					//cout<<"PARED EN FRENTE"<<endl;
					direction = (direction-1)%4;
					if(direction == -1){
						direction = 3;
					}
					just_change = true;
				}else{
					move_forward(position_x, position_y);
					my_key_type my_key(position_x,position_y);
					output[my_key]++;
				}
				//cout<<"<-"<<"("<<position_x<<","<<position_y<<") -> "<<direction<<"="<<print_dir(direction)<<endl;
				//cin>>i;
			}while( (position_x!=0 || position_y!=0) || just_change);
			
			for(it_type it = output.begin(); it!=output.end(); it++){
				solution[it->second]++;
			}

			solution[0] -= wall_blocks;

			for(i=0; i<5; i++){
				cout << right << setw(3) <<solution[i];
			}
			cout<<endl;
		}
	}

	return 0;
}