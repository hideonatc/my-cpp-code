#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length();
	int p[4]={0},pl=0,num_p=0;
	bool flag;
	for(int i=0;i<l;i++){
		flag=1;
		if(isdigit(s[i]))p[pl]=p[pl]*10+int(s[i])-48;
		else if(s[i]=='.'&&s[i+1]!='.'&&i!=l&&i!=0&&num_p<=3){
			pl++;
			num_p++;
		}
		else {
			flag=0;
			break;
		}
	}
	bool f=1;
	for(int i=0;i<4;i++){
		if(p[i]<0||p[i]>255){
			f=0;
			break;
		}
		else f=1;
	}
	if(!f||!flag||num_p!=3)cout<<"N";
	else if(p[0]>=1&&p[0]<=126)cout<<"A";
	else if(p[0]>=128&&p[0]<=191)cout<<"B";
	else if(p[0]>=192&&p[0]<=223)cout<<"C";
	else if(p[0]>=224&&p[0]<=239)cout<<"D";
	else if(p[0]>=240&&p[0]<=247)cout<<"E";
	else cout<<"X";
}
