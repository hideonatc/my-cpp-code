#include<iostream>
using namespace std;
long long int ans[100];
void dp(int a){
	for(int i=3;i<=a;i++)
		ans[i]=ans[i-1]+ans[i-2];
}
int main(){
	int n;
	cin>>n;
	ans[1]=1;
	ans[2]=2;
	dp(n);
	cout<<ans[n]<<" "<<ans[ans[n]%n]<<endl;
}