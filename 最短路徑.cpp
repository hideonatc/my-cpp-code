#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;
int r[101][101];
int dis[101];
bool check[101]={0};
int s,e;
void dijkstra(int n){
	int i,j;
	int pos;
	for(int i=1;i<=n;i++){
		dis[i]=r[i][s];
	}
	check[s]=true;
	int m=99999;
	for(int i=1;i<=n-1;i++){
		if(!check[i]&&dis[i]<m){
			m=dis[i];
			pos=i;
		}
	}
	check[pos]=1;
	for(int i=1;i<=n;i++){
		if(!check[i]&&dis[i]>dis[pos]+r[pos][i])
			dis[i]=dis[pos]+r[pos][i];
	}
	printf("%d",dis[e]);
} 
int main(){
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			r[i][j]=9999999;
	FILE *fp;
	fp=fopen("test.txt","r");
	fscanf(fp,"%d %d",&s,&e);
	int o,p;
	fscanf(fp,"%d %d",&o,&p);
	int a,b,c;
	for(int i=1;i<=o;i++){
		fscanf(fp,"%d %d %d",&a,&b,&c);
		r[a][b]=r[b][a]=c;
		r[i][i]=0;
	}
	fclose(fp);
	dijkstra(p);
}
