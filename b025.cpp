#include<iostream>
using namespace std;
long long int map[33][33]={0};
void dp(int x,int y){
	for(int i=0;i<=x;i++)
		map[i][0]=1;
	for(int i=0;i<=y;i++)
		map[0][i]=1;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			map[i][j]=map[i-1][j]+map[i][j-1];
		}
	}
	cout<<map[x][y]<<endl;
}
int main(){
	int x,y;
	cin>>x>>y;
	dp(x,y);
}