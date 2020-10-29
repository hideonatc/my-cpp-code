#include<iostream>
using namespace std;
int n,ans[102]={0};
bool used[102]={0};
void bt(int k){
	if(k==n+1){
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			ans[k]=i;
			bt(k+1);
			used[i]=0;
		}
	}
	return;
}
int main(){
	cin>>n;
	bt(1);
}