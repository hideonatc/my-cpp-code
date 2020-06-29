#include<iostream>
#include<cmath>
#include<set>
using namespace std;
bool solve(int p,int g){
	set<int> s;
	int k=1%p;
	s.insert(k);
	for(int i=1;i<=p-1;i++){
		k=(g*k)%p;
		s.insert(k);
	}
	if(s.size()==p-1)
		return true;
	return false;
}
int main(){
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<n-1;i++){
		if(solve(n,i)){
			cout<<i<<" ";
			ans++;
		}
	}
	cout<<endl;
	cout<<ans<<endl;
}