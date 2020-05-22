#include<iostream>
using namespace std;
int main(){
	string s;
	bool flag=false;
	int ans=0;
	cin>>s;
	int l=s.length();
	for(int i=3;i<=6;i++){
		for(int j=i;j<l;j++){
			if(s[j]!=s[j-i]){
				flag=false;
				break;
			}
			else flag=true;
		}
		if(flag&&l>=2*i){
			ans=i;
			break;
		}
	}
	printf("%d",ans);
}
