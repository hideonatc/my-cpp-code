#include<iostream>
#include<algorithm>
using namespace std;
int s[1001];
void solve(int a){
	int ans=0;
	for(int i=1;i<a;i++){
		ans+=(s[0]+s[1]);
		s[0]+=s[1];
		s[1]=9999999;
		sort(s,s+a);
		/*for(int j=0;j<a;j++)
			cout<<s[j]<<" ";
		cout<<endl;*/
	}
	cout<<ans<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n);
	solve(n);
}