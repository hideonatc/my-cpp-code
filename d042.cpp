#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string d,p;
		cin>>d>>p;
		int w=p.length()-1;
		int l=d.length();
		for(int i=1;i<=w;i++)
			d+='0';
		string s;
		for(int i=0;i<=w;i++)
			s+=d[i];
		for(int i=0;i<l;i++){
			if(s[0]>=p[0]){
				for(int j=0;j<w;j++){
					s[j]=char((int(s[j+1]-'0') xor (int(p[j+1]-'0')))+int('0'));
				}
				s[w]=d[i+w+1];
			}
			else{
				for(int j=0;j<w;j++){
					s[j]=char((int(s[j+1]-'0') xor 0)+int('0'));
				}
				s[w]=d[i+w+1];
			}
		}
		printf("CRC code:");
		for(int i=0;i<=w;i++)
			cout<<s[i];
		cout<<endl;
	}
}