#include<iostream>
using namespace std;
int conv(string s){
	int r=int(s[7]-'0')+int(s[6]-'0')*10+int(s[4]-'0')*60+int(s[3]-'0')*600+int(s[1]-'0')*3600+int(s[0]-'0')*36000;
	return r;
}
string rconv(int t){
	string r="";
	r+=char(t/36000+int('0'));
	t=t%36000;
	r+=char(t/3600+int('0'));
	t=t%3600;
	r+=':';
	r+=char(t/600+int('0'));
	t=t%600;
	r+=char(t/60+int('0'));
	t=t%60;
	r+=':';
	r+=char(t/10+int('0'));
	t=t%10;
	r+=char(t+int('0'));
	return r;
}
int main(){
	string t1,t2;
	cin>>t1>>t2;
	bool fl=0;
	if(t1==t2)
		cout<<"00:00:00"<<endl;
	else{
		int ans;
		if(t2<t1)
			ans=86400-conv(t1)+conv(t2);
		else
			ans=conv(t2)-conv(t1);
		string ans_t=rconv(ans);
		cout<<ans_t<<endl;
	}
}