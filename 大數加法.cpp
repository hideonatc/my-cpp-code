#include<iostream>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int la=a.length(),lb=b.length();
	if(la<lb){
		string s;
		s=a;	a=b;	b=s;
		int in;
		in=la;	la=lb;	lb=in;
	}
	int ans[101];
	int oa[101],ob[101];
	for(int i=0;i<la;i++)oa[i]=int(a[la-i-1])-48;
	for(int j=0;j<lb;j++)ob[j]=int(b[lb-j-1])-48;
	for(int m=lb;m<la;m++)ob[m]=0;
	int over=0;
	for(int k=0;k<la;k++){
		int p=oa[k]+ob[k]+over;
		over=0;
		if(p>=10){
			p-=10;
			over=1;
		}
		ans[k]=p;
	}
	if(over)cout<<1;
	for(int i=0;i<la;i++)cout<<ans[la-i-1];
}
