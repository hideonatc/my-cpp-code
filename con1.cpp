#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=i;j++)
			cout<<'*';
		for(int j=1;j<=2*n-2*i;j++)
			cout<<' ';
		for(int j=1;j<=i;j++)
			cout<<'*';
		cout<<endl;
	}
	for(int i=n-2;i>=0;i-=2){
		for(int j=1;j<=i;j++)
			cout<<'*';
		for(int j=1;j<=2*n-2*i;j++)
			cout<<' ';
		for(int j=1;j<=i;j++)
			cout<<'*';
		cout<<endl;
	}
}