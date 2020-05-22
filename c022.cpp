#include<iostream>
using namespace std;
int main(){
	int n,ans=1;
	cin>>n;
	while(n>=3){
		if(n%3==0)n/=3;
		else if(n%3==1)n=2*n+1;
		else if(n%3==2)n=2*n-1;
		ans++;
	}
	cout<<ans;
}
