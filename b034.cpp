#include<iostream>
using namespace std;
int c[10]={0,1,5,10,50,100,500,1000,5000,10000};
void solve(int a){
	int ans=0;
	int idx=9;
	while(a>0){
		while(c[idx]<=a){
			ans++;
			a-=c[idx];
		}
		idx--;
	}
	cout<<ans<<endl;
}
int main(){
	int n;
	cin>>n;
	solve(n);
}