#include<iostream>
#include<algorithm>
using namespace std;
string in[101],s;
bool used[101]={0};
int anss=0;
string ans[101],r_ans[101];
int id_ans=0;
bool copy(int id,int jd){
	char a[101],b[101];
	if(in[id].length()+jd>s.length())
		return 0;
	for(int i=0;i<in[id].length();i++)
		a[i]=in[id][i];
	for(int i=jd;i<=jd+in[id].length();i++)
		b[i-jd]=s[i];
	sort(a,a+in[id].length());
	sort(b,b+in[id].length());
	bool bl=1;
	for(int i=0;i<in[id].length();i++)
		if(a[i]!=b[i]){
			bl=false;
			break;
		}
	if(bl)
		return 1;
	return 0;
}
void bt(int idx,int n){
	//printf("bt(%d,%d)\n",idx,n);
	if(anss){
		anss++;
		return;
	}
	if(idx==s.length()){
		for(int i=0;i<id_ans;i++)
			r_ans[i]=ans[i];
		r_ans[id_ans]="-1";
		anss=1;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!used[i]&&copy(i,idx)){
				used[i]=1;
				ans[id_ans++]=in[i];
				bt(idx+in[i].length(),n);
				used[i]=0;
				id_ans--;
			}
		}
	}
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		int n;
		cin>>n;
		anss=0;
		for(int j=1;j<=n;j++)
			cin>>in[j];
		bt(0,n);
		if(!anss)
			cout<<"-1"<<endl;
		else if(anss==1){
			int j=0;
			while(r_ans[j]!="-1")
				cout<<r_ans[j++]<<" ";
			cout<<endl;
		}
		else
			cout<<"1"<<endl;
	}
}