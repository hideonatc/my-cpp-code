#include<iostream>
#define ulli unsigned long long int
using namespace std;
int ans[8];
void solve(ulli p,ulli q,ulli s){
	ulli n=q*p;
	ulli l=(ulli)s*s;
	ulli x=l%n;
	//printf("x=%lld n=%lld\n",x,n);
	for(int i=0;i<8;i++){
		ulli k=(x*x)%n;
		ans[i]=k%2;
		//printf("x=%d k=%d\n",x,k);
		x=k;
		cout<<ans[i];
	}
	cout<<" = ";
}
int pw(int a){
	int r=1;
	for(int i=1;i<=a;i++)
		r*=2;
	//cout<<r<<endl;
	return r;
}
int main(){
	ulli p,q,s;
	cin>>p>>q>>s;
	solve(p,q,s);
	int sum=0;
	for(int i=7;i>=0;i--){
		if(ans[i])
			sum+=pw(7-i);
	}
	cout<<hex<<uppercase;
	cout<<sum<<endl;
}