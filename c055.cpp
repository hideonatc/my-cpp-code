#include<iostream>
using namespace std;
int map[1000][1000];
int dijkstra(int n){
	int dis[1000]={0};
	bool vis[1000]={0};
	for(int i=1;i<=(n-1)*2;i++)
		dis[i]=map[1][i];
	vis[1]=1;
	for(int i=2;i<=(n-1)*2;i++){
		int mn=1e9+1,p;
		for(int j=1;j<=(n-1)*2;j++){
			if(dis[j]<mn&&!vis[j]){
				mn=dis[j];
				p=j;
			}
		}
		vis[p]=1;
		for(int j=1;j<=(n-1)*2;j++){
			if(!vis[j]&&dis[j]>map[p][j]+dis[p])
				dis[j]=map[p][j]+dis[p];
		}
	}
	if(dis[(n-1)*2]>1e8)
		return -1;
	return dis[(n-1)*2];
}
int main(){
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			map[i][j]=1e9;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>map[(i-1)*2][(i-1)*2+1];
	cin>>m;
	for(int i=1;i<=m;i++){
		int a,b,k;
		cin>>a>>b>>k;
		if(map[(a-1)*2+1][(b-1)*2]>k)
			map[(a-1)*2+1][(b-1)*2]=k;
	}
	cout<<dijkstra(n)<<endl;
}