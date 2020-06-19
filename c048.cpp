#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int ans=0,a=0,b=0,c=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='X'){
			if(a>=3&&b>=2&&c>=1)
				ans++;
			a=b=c=0;
		}
		else if(s[i]=='A')
			a++;
		else if(s[i]=='B')
			b++;
		else
			c++;
	}
	cout<<ans<<endl;
}