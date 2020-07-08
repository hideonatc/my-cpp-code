#include<iostream>
using namespace std;
string mx(string s1,string s2){
	return s1>s2?s1:s2;
}
int main(){
	string a,b,c;
	cin>>a>>b>>c;
	string ans=mx(mx(a+b+c,a+c+b),mx(b+a+c,b+c+a));
	ans=mx(ans,mx(c+a+b,c+b+a));
	cout<<ans<<endl;
}