#include<iostream>
using namespace std;
int p[5]={1,5,10,25,50};
int ans[1001]={1};
int solve(int a){
	for(int i=0;i<=4;i++){
		for(int j=p[i];j<=a;j++){
			ans[j]+=ans[j-p[i]];
		}
	}
	return ans[a];
}
int main(){
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
}