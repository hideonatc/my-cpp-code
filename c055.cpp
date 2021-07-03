#include<iostream>
#define MAX 100001
using namespace std;
int map[501][501],n;
int transport[501];
bool vis[501]={0};
int dis[501];
int dijkstra(){
	for(int i=1;i<=n;i++)
		dis[i]=map[1][i];
	vis[1]=1;
	for(int i=2;i<=n;i++){
		int mn=1e9,p;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<mn){
				mn=dis[j];
				p=j;
			}
		}
		vis[p]=true;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[p]+map[p][j]<dis[j])
				dis[j]=dis[p]+map[p][j];
	}
	return dis[n];
}
void print_map(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("from %d to %d is %d\n",i,j,map[i][j]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=MAX;
	for(int i=1;i<=n;i++)
		cin>>transport[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int a,b,k;
		cin>>a>>b>>k;
		map[a][b]=min(map[a][b],k);
		map[b][a]=min(map[b][a],k);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[j][i]+=transport[i];
	for(int i=1;i<=n;i++)
		map[i][i]=0;
	//print_map();
	int ans=dijkstra();
	if(ans>=MAX)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
}