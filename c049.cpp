#include<iostream>
using namespace std;
int return_h(int d,int k,int num[]){
	int h=d%997;
	for(int i=2;i<=k;i++){
		h=(h*7+num[d])%997;
		d=num[d];
	}
	return h;
}
int main(){
	int n;
	int num[200001]={0};
	int count[200001]={0};
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		num[a]=b;
		count[a]++;
		count[b]++;
	}
	int f;
	for(int i=1;i<=n;i++)
		if(count[i]!=2&&num[i]!=0){
			f=i;
			break;
		}
	cout<<return_h(f,n,num)<<endl;
}