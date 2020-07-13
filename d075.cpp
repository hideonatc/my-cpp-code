#include<iostream>
using namespace std;
int mxl=-1;
string ans[11],in[11],ansfn[11];
bool used[11]={0};
struct d{
	int x,y;
}r;
int mx_len(string a,string b,int ln){
	int al=a.length(),bl=b.length();
	for(int i=1;i<=bl;i++)
		for(int j=1;j<=min(i,min(al,bl));j++)
			if(a[al-j]==b[i-j])
				return ln+bl-i;
	for(int i=bl+1;i<=al+bl-1;i++)
		for(int j=1;j<=min(i-bl,min(al,bl));j++)
			if(a[al-j]==b[i-j])
				return ln;
	return 0;
}
d p(string a,string b){
	int al=a.length(),bl=b.length();
	for(int i=1;i<=bl;i++)
		for(int j=1;j<=min(i,min(al,bl));j++)
			if(a[al-j]==b[i-j]){
				r.x=al-j;
				r.y=i-j;
				return r;
			}
	for(int i=bl+1;i<=al+bl-1;i++)
		for(int j=1;j<=min(i-bl,min(al,bl));j++)
			if(a[al-j]==b[i-j]){
				r.x=al-j;
				r.y=i-j;
				return r;
			}
	return r;
}
bool f(int t){
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t;j++){
			if(in[j]==ans[i]&&in[j]!=ansfn[i])
				return 1;
			else if(in[j]==ansfn[i]&&in[j]!=ans[i])
				return 0;
		}
	}
	return 0;
}
void bt(int idx,int l,int e){
	if(idx==e+1){
		/*for(int i=1;i<=e;i++)
			cout<<ansfn[i]<<" ";
		cout<<l<<endl;*/
		if(mxl>l||(mxl==l&&!f(e)))
			return;
		for(int i=1;i<=e;i++)
			ans[i]=ansfn[i];
		mxl=l;
		return;
	}
	else{
		for(int i=1;i<=e;i++){
			if(!used[i]){
				if(idx>1){
					int len=mx_len(ansfn[idx-1],in[i],l);
					if(len){
						ansfn[idx]=in[i];
						used[i]=1;
						bt(idx+1,len,e);
						used[i]=0;
					}
				}
				else{
					ansfn[idx]=in[i];
					used[i]=1;
					bt(idx+1,in[i].length(),e);
					used[i]=0;
				}
			}
		}
	}
}
int spc=0;
void print(int t){
	for(int i=1;i<t;i++){
		d k=p(ans[i],ans[i+1]);
		for(int j=1;j<=spc;j++)
			cout<<"_";
		if(k.x-k.y<0)
			for(int j=1;j<=k.y-k.x;j++)
				cout<<"_";
		cout<<ans[i]<<endl;
		spc+=k.x-k.y;
	}
	for(int i=1;i<=spc;i++)
		cout<<"_";
	cout<<ans[t]<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	bt(1,0,n);
	print(n);
}