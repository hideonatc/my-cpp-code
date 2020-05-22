#include<iostream>
using namespace std;
int main(){
	string s;
	int ans,w,cnt;
	bool flag=false;
	while(cin>>s){
		ans=0;
		int l=s.length()-1;
		for(int i=0;i<=l;i++){
			if(isupper(s[i])){
				if(flag)	ans+=w;
				if(s[i]=='C')w=12;
				else if(s[i]=='H')w=1;
				else if(s[i]=='N')w=14;
				else w=16;
				cnt=0;
				flag=true;
			}
			else {
				flag=false;
				while(isdigit(s[i])){
					cnt=cnt*10+int(s[i])-48;
					i+=1;
				}
				i-=1;
			}
			ans+=cnt*w;
		}
		if(flag)  ans+=w;
		cout<<ans<<endl;
		flag=false;
	}
}
