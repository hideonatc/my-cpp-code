#include<iostream>
#include<set>
using namespace std;
int main(){
	int m;
	cin>>m;
	int ans[999],f=0;
	multiset<int> n;
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		n.insert(a);
	}
	for(multiset<int>::iterator it=n.begin();it!=n.end();it++){
		ans[m-f-1]=*it;
		f++;
	}
	for(int i=0;i<m-1;i++)
		cout<<ans[i]<<" ";
	cout<<ans[m-1];
}
