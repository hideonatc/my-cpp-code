#include<iostream>
using namespace std;
int main(){
	long long int f=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		f+=15*i*i*i;
	}
	printf("F=%lld",f);
}
