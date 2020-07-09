#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int h=0,m=0;
	if(s[1]==':'){
		h=int(s[0]-'0');
		m=int(s[2]-'0')*10+int(s[3]-'0');
	}
	else{
		h=int(s[0]-'0')*10+int(s[1]-'0');
		h=h%12;
		m=int(s[3]-'0')*10+int(s[4]-'0');
	}
	double ma=6*m;
	double ha=30*h+(double)m*0.5;
	double ans=ma-ha;
	if(ans<0)ans=-ans;
	if(ans>180)
		printf("%.2f\n",360-ans);
	else
		printf("%.2f\n",ans);
}