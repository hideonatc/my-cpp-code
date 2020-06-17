#include<iostream>
#include<algorithm>
using namespace std;
int b[10001];
void solve(int a){
	long long int ans=0;
	for(int i=1;i<a;i++){
		for(int j=0;j<i;j++){
			ans+=b[j];
		}
	}
	cout<<ans*100<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>b[i];
	sort(b,b+n);
	solve(n);
}