#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int mx=-1e9,mn=1e9,sum=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		sum+=k;
		if(k>mx)
			mx=k;
		if(k<mn)
			mn=k;
	}
	printf("%.2f\n",float(sum)/float(n));
	printf("%d\n%d\n",mx,mn);
}