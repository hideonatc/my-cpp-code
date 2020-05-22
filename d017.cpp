#include<iostream>
#include<set>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length();
	int ans[999],f=0;
	multiset<int> n;
	for(int i=0;i<l;i++)
		n.insert(int(s[i])-48);
	for(multiset<int>::iterator it=n.begin();it!=n.end();it++){
		ans[l-f-1]=*it;
		f++;
	}
	for(int i=0;i<l;i++)
	cout<<ans[i];
}
