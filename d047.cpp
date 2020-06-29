#include<iostream>
using namespace std;
string s1,s2,ans;
void add(){
	int l2=s2.length(),la=ans.length();
	for(int i=1;i<=l2-la;i++)
		ans+='0';
	int k=0;
	for(int i=0;i<l2;i++){
		int b=k+int(s2[i]-'0')+int(ans[i]-'0');
		ans[i]=char(b%10+int('0'));
		k=b/10;
	}
	if(k!=0)
		ans+=char(k+int('0'));
}
void f(int a){
	s1="1";
	for(int i=1;i<=a;i++){
		int k=0;
		for(int j=0;j<s1.length();j++){
			int b=k+int(s1[j]-'0')*2;
			k=b/10;
			s1[j]=char(b%10+int('0'));
		}
		if(k!=0){
			s1+=char(k+int('0'));
		}
	}
	ans=s1;
}
void solve(){
	s2=s1;
	int l2=s2.length(),l1=s1.length();
	int k=0;
	for(int i=0;i<l2;i++){
		int b=k+int(s1[i]-'0')+int(s2[i]-'0');
		s2[i]=char(b%10+int('0'));
		k=b/10;
	}
	if(k!=0)
		s2+=char(k+int('0'));
	add();
	s1=s2;
}
int main(){
	int n,m;
	cin>>n>>m;
	if(n>m)
		printf("n=%d比m=%d大，輸入錯誤\n",n,m);
	else{
		f(n);
		for(int i=n+1;i<=m;i++)
			solve();
		for(int i=ans.length()-1;i>=0;i--)
			cout<<ans[i];
		cout<<endl;
	}
}