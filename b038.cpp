#include<iostream>
using namespace std;
int ans[11];
bool used[11]={0};
void solve(int a,int p){
	if(p==a+1){
		for(int i=1;i<=a;i++)
			cout<<ans[i];
		cout<<endl;
		return;
	}
	else{
		for(int i=1;i<=a;i++){
			if(!used[i]){
				ans[p]=i;
				used[i]=true;
				solve(a,p+1);
				used[i]=false;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	solve(n,1);
}