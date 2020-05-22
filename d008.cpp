#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		int l=s.length();
		if(l%2!=0)s=s+'X';
		l=s.length();
		int num[9999];
		for(int j=0;j<=l-1;j++){
			if(isupper(s[j]))num[j]=int(s[j])-65;
			else num[j]=int(s[j])-97;
		}
		for(int j=0;j<=l-1;j+=2){
			num[j]=(num[j]*1+num[j+1]*3)%26;
			num[j+1]=(num[j+1]*2)%26;
			s[j]=char(num[j]+65);
			s[j+1]=char(num[j+1]+65);
		}
		cout<<s<<endl;
	}
}
