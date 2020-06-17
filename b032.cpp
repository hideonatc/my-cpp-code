#include<iostream>
using namespace std;
int score[101];
int ans[101];
void solve(int a){
	int m=-1;
	ans[1]=1;
	for(int i=2;i<=a;i++){
		int k=-1,p=-1;
		for(int j=i;j>0;j--){
			if(score[j]<score[i]){
				if(ans[j]>k)
					k=ans[j];
			}
		}
		if(k!=-1){
			ans[i]=k+1;
			if(m<ans[i])
				m=ans[i];
		}
		else
			ans[i]=1;
	}
	cout<<m<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>score[i];
	solve(n);
}
//10 46 98 31 74 49 66 46 95 96 35