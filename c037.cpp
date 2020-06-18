#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int pos[10001],p;
	for(int i=1;i<=n;i++){
		cin>>p;
		pos[p]=i;
	}
	int ans=0;
	for(int i=1;i<n;i++)
		ans+=abs(pos[i+1]-pos[i]);
	cout<<ans<<endl;
}