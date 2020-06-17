#include<iostream>
using namespace std;
int num[21];
bool used[21]={0},f=false;
int n,m;
void bt(int s,int d){
	if(s==m){
		f=true;
		for(int i=0;i<d;i++)
			if(used[i])
				cout<<num[i]<<" ";
		cout<<endl;
		return;
	}
	if(d==n||s>m)
		return;
	used[d]=true;
	bt(s+num[d],d+1);
	used[d]=false;
	bt(s,d+1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
	bt(0,0);
	if(!f)
		cout<<"NO"<<endl;
}