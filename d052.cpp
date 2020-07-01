#include<iostream>
using namespace std;
string t="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string t2="abcdefghijklmnopqrstuvwxyz";
int main(){
	string s;
	int count[26]={0};
	while(cin>>s){
		if(cin.fail()){
			break;
		}
		for(int i=0;i<s.length();i++){
			for(int j=0;j<26;j++){
				if(s[i]==t[j]||s[i]==t2[j]){
					count[j]++;
					break;
				}
			}
		}
	}
	for(int i=0;i<26;i++)
		cout<<t[i]<<" ";
	cout<<endl;
	for(int i=0;i<26;i++)
		cout<<count[i]<<" ";
	cout<<endl;
}