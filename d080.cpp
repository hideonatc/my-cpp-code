#include<iostream>
using namespace std;
long long int map[21][21];
long long int solve(int x,int y){
	for(int i=1;i<=x;i++)
		map[i][1]=1;
	for(int i=1;i<=y;i++)
		map[1][i]=1;
	for(int i=2;i<=x;i++)
		for(int j=2;j<=y;j++)
			map[i][j]=map[i-1][j]+map[i][j-1];
	return map[x][y];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
}