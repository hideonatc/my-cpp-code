#include<iostream>
using namespace std;
bool isprime(long int a){
	if(a==2)
		return 1;
	for(long int i=2;i<=a/2+1;i++){
		if(a%i==0)
			return 0;
	}
	return 1;
}
int main(){
	long int n;
	cin>>n;
	bool flag=0;
	for(int i=2;n>1;i++){
		while(n%i==0){
			if(flag)
				cout<<" * "<<i;
			else{
				flag=1;
				cout<<n<<" = "<<i;
			}
			n/=i;
		}
	}
	cout<<endl;
}