#include<iostream>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int ans[104]={0};
	if(s1<s2){
		string s=s1;
		s1=s2;
		s2=s;
	}
	int l1=s1.length(),l2=s2.length();
	for(int i=0;i<=(l1-1)/2;i++)
		swap(s1[i],s1[l1-1-i]);
	for(int i=0;i<=(l2-1)/2;i++)
		swap(s2[i],s2[l2-1-i]);
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
	for(int i=l-1;i>=0;i--)
		cout<<ans[i];
	cout<<endl;
}