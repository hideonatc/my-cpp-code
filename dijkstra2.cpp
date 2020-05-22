#include<iostream>
#include<cstring>
using namespace std;
int map[4][4];
int dis[4];
int e=3;
bool vis[4]={0};
int dijkstra(void){
	vis[0]=1;
	for(int i=0;i<4;i++)dis[i]=map[0][i];
	int m=99999;
	int pos;
	for(int i=0;i<3;i++){
		if(!vis[i]&&dis[i]<m){
			pos=i;
			m=dis[i];
		}
	}
	vis[pos]=true;
	for(int i=0;i<4;i++){
		if(!vis[i]&&dis[i]>dis[pos]+map[pos][i]){
			dis[i]=dis[pos]+map[pos][i];
		}
	}
		cout<<dis[e];
}
int main(){
	memset(map,99999,sizeof(map));
	for(int i=0;i<6;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	for(int i=0;i<4;i++)map[i][i]=0;
	dijkstra();
}
