#include<iostream>
#include<set>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	multiset<int> s;
	for(int i=1;i<=n;i++){
		int in;
		cin>>in;
		s.insert(in);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int in;
		cin>>in;
		s.insert(in);
	}
	for(multiset<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<*it;
		if(it!=s.end())cout<<" ";
	}
}
