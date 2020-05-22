#include<iostream>
using namespace std;
char pf[5][5]={{'L','O','V','E','I'},{'S','A','M','N','Y'},{'P','D','R','T','H'},{'G','B','C','F','K'},{'Q','U','W','X','Z'}};
string ans="0";
int chk_pos_x(char a){
	int pos;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(pf[i][j]==a)pos=i;
		}
	}
	return pos;
}
int chk_pos_y(char a){
	int pos;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(pf[i][j]==a)pos=j;
		}
	}
	return pos;
}
void playfair(char a,char b){
	char c,d;
	if(chk_pos_x(a)==chk_pos_x(b)){
		c=pf[chk_pos_x(a)][(chk_pos_y(a)+1)%5];
		d=pf[chk_pos_x(b)][(chk_pos_y(b)+1)%5];
	}
	else if(chk_pos_y(a)==chk_pos_y(b)){
		c=pf[(chk_pos_x(a)+1)%5][chk_pos_y(a)];
		d=pf[(chk_pos_x(b)+1)%5][chk_pos_y(b)];
	}
	else {
		c=pf[chk_pos_x(b)][chk_pos_y(a)];
		d=pf[chk_pos_x(a)][chk_pos_y(b)];
	}
	ans+=c;
	ans+=d;
}
int main(){
	string s,k;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
		if(s[i]=='J')s[i]='I';
	for(int i=0;i<l;i+=2){
		if(s[i]==s[i+1]){
			k=s[0];
			for(int j=1;j<=i;j++){
				k+=s[j];
			}
			k+='X';
			for(int j=i+1;j<l;j++){
				k+=s[j];
			}
			s=k;
			l=s.length();
		}
	}
	if(l%2){
		s+='X';
		l=s.length();
	}
	//	cout<<s<<endl;
	for(int i=0;i<l;i+=2){
		playfair(s[i],s[i+1]);
	}
	for(int i=1;i<=l;i++)
		cout<<ans[i];
}
