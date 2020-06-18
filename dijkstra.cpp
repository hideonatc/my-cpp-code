//wrong!!
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int r[101][101];
int dis[101];
int s,e;
bool vis[101]={0};
void dijkstra(int n){
	for(int i=1;i<=n;i++){
		dis[i]=r[i][s];
	}
	vis[s]=true;
	int m=99999;
	int pos;
	for(int i=1;i<=n-1;i++){
		if(!vis[i]&&dis[i]<m){
			m=dis[i];
			pos=i;
		}
	}
	vis[pos]=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&dis[i]>dis[pos]+r[i][pos]){
			dis[i]=dis[pos]+r[i][pos];
		}
	}
	printf("%d",dis[e]);
}
int main(){
	memset(r,99999,sizeof(r));
	int o,p;
	cin>>o>>p>>s>>e;
	int a,b,c;
	for(int i=1;i<=o;i++){
		cin>>a>>b>>c;
		r[a][b]=r[b][a]=c;
		r[i][i]=0;
	}
	dijkstra(p);
}
