#include<iostream>
using namespace std;
int main(){
	int count[4]={0,0,0,0},ans=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='H')
			count[0]++;
		else if(s[i]=='A')
			count[1]++;
		else if(s[i]=='P')
			count[2]++;
		else if(s[i]=='Y')
			count[3]++;
	}
	while(count[0]&&count[1]&&count[2]>=2&&count[3]){
		ans++;
		count[0]--;
		count[1]--;
		count[2]-=2;
		count[3]--;
	}
	cout<<ans<<endl;
}