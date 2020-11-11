#include<iostream>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	if(a.length()>b.length())
		for(int i=1;i<=a.length()-b.length();i++)
			b='0'+b;
	else
		for(int i=1;i<=b.length()-a.length();i++)
			a='0'+a;
	bool flag=false;
	if(a<b){
		flag=true;
		string s;
		s=a; a=b; b=s;
	}
	cout<<a<<endl<<b<<endl;
	string ans="";
	for(int i=a.length()+1;i>=0;i--){
		int num_a=int(a[i]-int('0')),num_b=int(b[i]-int('0'));
		if(a[i]<b[i]){
			int j=1;
			while(a[i+j]!='0')
				j++;
			a[i+j]--;
			for(int k=i+j-1;k!=i;k--)
				a[k]='9';
			num_a+=10;
		}
		ans=char(num_a-num_b+int('0'))+ans;
	}
	int idx=0;
	while(ans[idx]=='0')
		idx++;
	if(flag)cout<<'-';
	for(int i=idx;i<=ans.length()-3;i++)
		cout<<ans[i];
	cout<<endl;
}