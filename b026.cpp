#include<iostream>
using namespace std;
int num[101];
int dp[101];
void solve(int a){
	int sum=0,max=-1;
	for(int i=1;i<=a;i++){
		sum+=num[i];
		if(sum<0)
			sum=0;
		if(sum>=max)
			max=sum;
	}
	cout<<max<<endl;
}
int main(){
	int n; 
	cin>>n;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]>0)
			f=true;
	}
	if(f)
		solve(n);
	else 
		cout<<"0"<<endl;
}