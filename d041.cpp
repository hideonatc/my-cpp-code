#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int ans=0;
	bool flag=1;
	for(int i=0;i<s.length();i++){
		if(s[i]!='1'&&s[i]!='0'){
			cout<<s<<"非二進位數"<<endl;
			flag=0;
			break;
		}
		if(s[i]=='1')
			ans++;
	}
	if(flag)
		printf("包含1的個數為%d\n",ans);
}