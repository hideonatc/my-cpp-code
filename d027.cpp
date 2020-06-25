#include<iostream>
#include<map>
#include<cmath>
using namespace std;
map<char,int> m;
void solve(string s){
	int ans=0,l=s.length();
	for(int i=0;i<l;i++)
		ans+=m[s[l-i-1]]*pow(16.0,i);
	cout<<ans<<endl;
}
int main(){
	for(int i=0;i<=9;i++)
		m[char(i+int('0'))]=i;
	m['A']=10;
	m['B']=11;
	m['C']=12;
	m['D']=13;
	m['E']=14;
	m['F']=15;
	for(int i=1;i<=20;i++){
		string s;
		cin>>s;
		solve(s);
	}
}