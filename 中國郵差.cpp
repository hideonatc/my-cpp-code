#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int r[101][101],dis[101];
bool vis[101]={0};
int s,e;
void dijkstra(int n){
	for(int i=1;i<=n;i++)dis[i]=r[i][s];
	vis[s]=true;
	int m=99999,pos;
	for(int i=1;i<n;i++){
		if(!vis[i]&&dis[i]<m){
			m=dis[i];
			pos=i;
		}
	}
	for(int i=i;i<=n;i++){
		if(!vis[i]&&dis[i]>dis[pos]+r[i][pos]){
			dis[i]=dis[pos]+r[i][pos];
		}
	}
}
int main(){
	int o,p;
	cin>>o>>p>>s>>e;
	memset(r,0,sizeof(r));
	int a,b,c;
	for(int i=1;i<=o;i++){
		cin>>a>>b>>c;
		r[a][b]=r[b][a]=c;
		r[i][i]=0;
	}
	dijkstra(p);
	cout<<dis[1]<<dis[2]<<dis[3]<<dis[4];
}
