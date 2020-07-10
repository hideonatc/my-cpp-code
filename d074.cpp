#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	char t,T;
	cin>>t;
	if(isupper(t))
		T=char(int(t)+32);
	else
		T=char(int(t)-32);
	int st=0;
	while(s[st]!=T&&s[st]!=t)
		st++;
	for(int i=st+1;i<s.length();i++){
		if(s[i]==t||s[i]==T){
			cout<<i-st<<" ";
			st=i;
		}
	}
	cout<<endl;
}