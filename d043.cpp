#include<iostream>
#include<map>
using namespace std;
string ch="零一二三四五六七八九";
int main(){
	int t=0;
	map<int ,string> s;
	string in;
	//int n;
	//cin>>n;
	while(cin>>in){
		//cin>>in;
		if(cin.fail())
			break;
		if(isdigit(in[0])){
			int ans=0;
			for(int i=0;i<in.length();i++)
				ans=ans*10+int(in[i]-'0');
			s[ans]=in;
		}
		else{
			int ans=0;
			for(int i=0;i<in.length();i+=3){
				for(int j=0;j<ch.length();j+=3){
					if(ch[j]==in[i]&&ch[j+1]==in[i+1]&&ch[j+2]==in[i+2]){
						ans=ans*10+j/3;
						break;
					}
				}
			}
			s[ans]=in;
		}
	}
	for(map<int ,string>::iterator it=s.begin();it!=s.end();it++)
		cout<<it->second<<endl;
}