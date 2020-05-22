#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
bool vis[7]={0};
int parent[7]={0,1,2,3,4,5,6};
int num[7]={1};
struct node{
	int start;
	int end;
	int w;
};
node r[12];
bool compare(node a,node b){
	return a.w<b.w;
}
bool isend(void){
	bool flag=1;
	int ind=parent[0];
	for(int i=1;i<7;i++){
		if(parent[i]!=ind)
			flag=false;
	}
	return flag;
}
int find_parent(int a){
	while(a!=parent[a]){
		a=parent[a];
	}
	return a;
}
int kruskal(void){
	int ans=0;
		for(int i=0;i<12;i++){
		if(isend())break;
		if(vis[r[i].start]&&vis[r[i].end])continue;
		int a=find_parent(r[i].start);
		int b=find_parent(r[i].end);
		if(a!=b){
			if(num[a]>num[b]){
				parent[b]=a;
				num[a]+=num[b];
			}
			else {
				parent[a]=b;
				num[b]+=num[a];
			}
			cout<<r[i].start<<" "<<r[i].end<<endl;
			ans+=r[i].w;
		}
	}
	cout<<ans;
}
int main(){
	FILE *f;
	f=fopen("data.txt","r");
	for(int i=0;i<12;i++){
		//cin>>r[i].start>>r[i].end>>r[i].w;
		fscanf(f,"%d %d %d",&r[i].start,&r[i].end,&r[i].w);
	}
	sort(r,r+11,compare);
	kruskal();
}
