#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A'&&i+1<s.length()){
			if(s[i+1]=='C'){
				ans++;
				i=i+1;
			}
		}
		else
			continue;
	}
	cout<<ans<<endl;
}