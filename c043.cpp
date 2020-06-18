#include<iostream>
#include<cmath>
using namespace std;
int map[101][101];
int dis[101];
bool vis[101]={0};
void solve(int n,int m){
	for(int i=1;i<=n;i++){
		dis[i]=map[1][i];
		//printf("dis[%d]=%d\n",i,dis[i]);
	}
	vis[1]=true;
	for(int k=1;k<=n;k++){
		int mn=999999,pos;
		for(int i=1;i<=n-1;i++){
			if(!vis[i]&&dis[i]<mn){
				mn=dis[i];
				pos=i;
			}
		}
		vis[pos]=true;
		//printf("vis[%d]=true\n",pos);
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]>map[pos][i]+dis[pos]){
				dis[i]=dis[pos]+map[pos][i];
				//printf("dis[%d]=dis[%d]+map[%d][%d]=%d\n",i,pos,pos,i,dis[i]);
			}
		}
	}
	cout<<dis[n]<<endl;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			map[i][j]=map[j][i]=abs(j-i)*100;
	int k,a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>k;
		if(map[a][b]>k&&map[b][a]>k)
			map[a][b]=map[b][a]=k;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}*/
	solve(n,m);
}