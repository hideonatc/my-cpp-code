#include<iostream>
using namespace std;
int ans[11];
void solve(int a,int b,int p){
	if(p==a+1){
		for(int i=1;i<=a;i++)
			cout<<ans[i];
		cout<<endl;
		return;
	}
	else{
		for(int i=0;i<=b;i++){
			ans[p]=i;
			solve(a,b,p+1);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	solve(n,m,1);
}