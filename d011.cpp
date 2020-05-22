#include<iostream>
using namespace std;
int main(){
	unsigned long long int ans=0,s=0;
	int u,l;
	cin>>l>>u;
	int a;
	for(int i=l;i<=u;i++){
		int k=i;
		s+=k;
		while(k!=1){
			if(k%2==0)k/=2;
			else k=k*3+1;
			s+=k;
		}
		if(s>ans){
			ans=s;
			a=i;
		}
		s=0;
	}
	cout<<ans<<" "<<a;
}
