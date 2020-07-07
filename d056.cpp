#include<iostream>
using namespace std;
int d[101][101];
string st;
int w(char a,char b){
	if(a=='A')
		if(b=='U')
			return 1;
	if(a=='U')
		if(b=='A')
			return 1;
	if(a=='C')
		if(b=='G')
			return 1;
	if(a=='G')
		if(b=='C')
			return 1;
	return 0;
}
void print(){
	int l=st.length();
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			printf("%3d",d[i][j]);
		}
		cout<<endl;
	}
}
int solve(int s,int e){
	if(d[s][e]!=-1)
		return d[s][e];
	if(s==e){
		d[s][e]=0;
		return 0;
	}
	if(s==e+1){
		d[s][e]=0;
		return 0;
	}
	int a=solve(s+1,e);
	int b=solve(s,e-1);
	int c=solve(s+1,e-1)+w(st[s],st[e]);
	int f=-1;
	for(int i=s+1;i<e;i++){
		if(f<solve(s,i)+solve(i+1,e))
			f=solve(s,i)+solve(i+1,e);
	}
	int r=max(max(a,b),max(c,f));
	d[s][e]=r;
	return r;
}
int main(){
	cin>>st;
	for(int i=0;i<=st.length();i++)
		for(int j=0;j<=st.length();j++)
			d[i][j]=-1;
	cout<<solve(0,st.length()-1)<<endl;
	//print();
}