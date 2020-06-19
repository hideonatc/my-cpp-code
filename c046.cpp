#include<iostream>
using namespace std;
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	printf("%d.",a/b);
	a=a%b;
	for(int i=1;i<=n;i++){
		int k=a*10/b;
		cout<<k;
		a=(a*10)%b;
	}
	cout<<endl;
}