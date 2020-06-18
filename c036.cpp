#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n;
	int mx=-1,mn=99999999,s_mx=-1,s_mn=99999999;
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>mx){
			s_mx=mx;
			mx=k;
		}
		else if(k>s_mx)
			s_mx=k;
		if(k<mn){
			s_mn=mn;
			mn=k;
		}
		else if(k<s_mn)
			s_mn=k;
	}
	cout<<s_mx-s_mn<<endl;
}