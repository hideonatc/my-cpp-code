#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num[100000];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	cout<<num[n/2+1]<<endl;
}