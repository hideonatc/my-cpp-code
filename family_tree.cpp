#include<iostream>
using namespace std;
int n,s;
bool vis[999]={0};
int map[999][999];
int dis[999];
int dijkstra(int a){
	for(int i=0;i<n;i++){
		dis[i]=map[i][s];
	}
	vis[s]=1;
	int min;
	int pos;
	for(int j=0;j<n-1;j++){
		pos=s;	
		min=99999;
		for(int i=0;i<n;i++){
			if(!vis[i]&&dis[i]<min){
				pos=i;
				min=dis[i];
			}
		}
		vis[pos]=1;
		for(int i=0;i<n;i++){
			if(!vis[i]&&dis[i]>dis[pos]+map[i][pos]){
				dis[i]=dis[pos]+map[i][pos];
			}
		}
	}
	return dis[a];
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			map[i][j]=9999;
		}
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		map[a][b]=map[b][a]=1;
	}
	for(int i=0;i<n;i++)map[i][i]=0;
	cin>>s;
	int max=-1,max_pos;
	for(int i=0;i<n;i++){
		int d=dijkstra(i);
		cout<<i<<" "<<d<<endl;
		if(d>max){
			max=d;
			max_pos=i;
		}
	}
	printf("%d %d",max,max_pos);
}
