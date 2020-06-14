#include<iostream>
using namespace std;
string num[1001]={""};
void num_to_string(int i,int t){
	while(t>0){
		num[i]+=char(t%10+int('0'));
		t/=10;
	}
}
void solve(int n,int now,string s1){
	if(now==n+1){
		int l=s1.length();
		for(int i=l-1;i>=0;i--)
			cout<<s1[i];
		cout<<endl;
	}
	else{
		string s2=num[now];
		int l1=s1.length(),l2=s2.length();
		string s;
		int ans[3001]={0};
		int a=0,b;
		bool g=0;
		for(int i=0;i<l2;i++){
			for(int j=0;j<l1;j++){
				int n1=int(s1[j]-'0');
				int n2=int(s2[i]-'0');
				int t=n1*n2+ans[i+j];
				b=t%10;
				a=t/10;
				if(a)
					g=true;
				else
					g=false;
				ans[i+j+1]+=a;
				ans[i+j]=b;
			}
		}
		int l=g?(l1+l2):(l1+l2-1);
		for(int i=0;i<l;i++)
			s+=char(ans[i]+int('0'));
		solve(n,now+1,s);
	}
}
int main(){
	int n;
	cin>>n;
	num[0]="1";
	for(int i=1;i<=n;i++){
		int t=i;
		num_to_string(i,t);
	}
	solve(n,1,num[0]);
}