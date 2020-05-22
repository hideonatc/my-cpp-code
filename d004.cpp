#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int cell[7][7]={2};
int cell2[7][7];
int near_by(int x,int y){
	int n=0;
	if(cell[x-1][y-1]==1)n++;
	if(cell[x-1][y]==1)n++;
	if(cell[x-1][y+1]==1)n++;
	if(cell[x][y-1]==1)n++;
	if(cell[x][y+1]==1)n++;
	if(cell[x+1][y-1]==1)n++;
	if(cell[x+1][y]==1)n++;
	if(cell[x+1][y+1]==1)n++;
	return n;
}
void copy(void){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cell[i][j]=cell2[i][j];
		}
	}
}
void judge(int x,int y){
	int live=near_by(x,y);
	if(cell[x][y]){
		if(live<=1)cell2[x][y]=0;
		else if(live<=3)cell2[x][y]=1;
		else cell2[x][y]=0;
	}
	else if(!cell[x][y]){
		if(live==3)cell2[x][y]=1;
		else cell2[x][y]=0;
	}
}
int main(){
	for(int i=1;i<=5;i++){
		scanf("%d,%d,%d,%d,%d",&cell[i][1],&cell[i][2],&cell[i][3],&cell[i][4],&cell[i][5]);
	}
	for(int k=2;k<=5;k++){
		int l=0;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=5;j++){
				judge(i,j);
				if(cell2[i][j]==1)l++;
			}
		}
		printf("第%d代: %d個細胞存活\n",k,l);
		for(int i=1;i<=5;i++){
			for(int j=1;j<=5;j++){
				if(j<=4)printf("%d,",cell2[i][j]);
				else printf("%d\n",cell2[i][j]);
			}
		}
		copy();
	}
}
