#include<iostream>
using namespace std;
int c[6]={1,5,10,12,16,20};
int ans[101];
void solve(int a){
	for(int i=1;i<=100;i++)
		ans[i]=150;
	ans[0]=0;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=5;j++){
			if((ans[i+c[j]]>ans[i]+1)&&!(i+c[j]>a))
				ans[i+c[j]]=ans[i]+1;
		}
	}
	cout<<ans[a]<<endl;
}
int main(){
	int n;
	cin>>n;
	solve(n);
}