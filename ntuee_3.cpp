#include<iostream>
#include<algorithm>
using namespace std;
int coin[12]={0};
int ans[11]={0};
int m,n,cnt=0;
bool compare(int a,int b){
	return a>b;
}
void bt(int idx,int now,int arr_idx){
	if(now==n){
		cnt++;
		for(int i=1;i<=idx;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=arr_idx;i<=m;i++){
		if(now+coin[i]<=n){
			ans[idx+1]=coin[i];
			bt(idx+1,coin[i]+now,i);
		}
	}
	return;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>coin[i];
	sort(coin+1,coin+1+m,compare);
	bt(0,0,1);
	cout<<cnt<<endl;
}