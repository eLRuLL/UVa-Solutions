#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#define pb push_back
#define MAX 1000000
using namespace std;
int main()
{
int row,col,moves;

while(scanf("%d %d",&row,&col)&& (row || col))
{ if(row==1 || col==1)
moves=max(row,col);
else if(row==2 || col==2)
moves = (min((max(row,col) % 4), 2)) * 2 + (max(row,col)/4) * 4;
else
moves=(row*col+1)/2;
printf("%d knights may be placed on a %d row %d column board.\n",moves,row,col);
}

return 0;
}