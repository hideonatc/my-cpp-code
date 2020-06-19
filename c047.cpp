#include<iostream>
using namespace std;
int main(){
	int n;
	long long int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		ans+=((k-2)*(k-2));
	}
	cout<<ans<<endl;
}