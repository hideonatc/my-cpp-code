#include<iostream>
using namespace std;
int solve(int a,int b){
	int n=min(a,b);
	while(1){
		if(n%a==0&&n%b==0)
			return n;
		n+=min(a,b);
	}
	return a*b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<solve(a,b)<<endl;
	}
}