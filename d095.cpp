#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	string s1,s2;
	getline(cin,s1);
	while(t--){
		getline(cin,s1);
		getline(cin,s2);
		int tab[26]={0};
		for(int i=0;i<s1.length();i++){
			if(isalpha(s1[i])){
				if(isupper(s1[i]))
					tab[int(s1[i])-65]++;
				else
					tab[int(s1[i])-97]++;
			}
		}
		for(int i=0;i<s2.length();i++){
			if(isalpha(s2[i])){
				if(isupper(s2[i]))
					tab[int(s2[i])-65]--;
				else
					tab[int(s2[i])-97]--;
			}
		}
		int ans=1;
		for(int i=0;i<26;i++)
			if(tab[i]!=0){
				ans=0;
				break;
			}
		cout<<ans<<endl;
	}
}