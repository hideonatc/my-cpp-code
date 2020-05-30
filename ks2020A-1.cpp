#include<iostream>
#include<set>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,b;
		cin>>n>>b;
		multiset<int> s;
		for(int j=1;j<=n;j++){
			int k;
			cin>>k;
			s.insert(k);
		}
		int ans=0;
		for(multiset<int>::iterator it=s.begin();it!=s.end();it++){
			if(b-*it>=0){
				b-=*it;
				ans++;
			}
			else break;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}