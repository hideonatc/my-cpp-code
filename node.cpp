#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int s;
	int e;
	int w;
};
bool vis[101]={0};
bool isend(int p){
	bool flag=1;
	for(int i=1;i<=p;i++){
		if(!vis[i]){
			flag=0;
			break;
		}
	}
	return flag;
}
bool compare(node a, node b) {
	return a.w<b.w;
}
int main(){
	int n,m;
	vector<node> r;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>r[i].s>>r[i].e>>r[i].w;
	}
	sort(r.begin(),r.end(),compare);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(isend(n))break;
		if(!vis[r[i].s]||!vis[r[i].e]){
			vis[r[i].s]=vis[r[i].e]=1;
			ans+=r[i].w;
		}
	}
	cout<<ans;
}