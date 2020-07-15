#include<iostream>
using namespace std;
bool judge(string a,string b){
	if(a.length()<b.length())
		return 1;
	if(a.length()==b.length())
		return a<b;
	return 0;
}
int main(){
	string s1,s2;
	while(cin>>s1){
		if(s1=="EOF")
			break;
		cin>>s2;
		if(judge(s1,s2)){
			string s;
			s=s2;
			s2=s1;
			s1=s;
		}
		if(s1==s2)
			cout<<'0'<<endl;
		else{
			string ans="";
			//cout<<s1.length()<<" "<<s2.length()<<endl;
			for(int i=s2.length();i<=s1.length()-1;i++)
				s2='0'+s2;
			//cout<<s1<<endl<<s2<<endl;
			for(int i=s1.length()-1;i>=0;i--){
				if(s1[i]<s2[i]){
					ans=char(int(s1[i])+10-int(s2[i])+int('0'))+ans;
					int idx=i;
					while(s1[idx-1]=='0'&&idx-1>=0){
						s1[idx-1]='9';
						idx--;
					}
					s1[idx-1]-=1;
				}
				else{
					ans=char(int(s1[i])-int(s2[i])+int('0'))+ans;
				}
			}
			int idx=0;
			while(ans[idx]=='0')
				idx++;
			for(int i=idx;i<ans.length();i++)
				cout<<ans[i];
			cout<<endl;
		}
	}
}