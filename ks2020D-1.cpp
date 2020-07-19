#include<iostream>
using namespace std;
int main(){
	int t,k;
	cin>>t;
	k=t;
	while(t--){
		int n;
		cin>>n;
		int num[200005];
		for(int i=1;i<=n;i++)
			cin>>num[i];
		int mx=-1,ans=0;
		for(int i=1;i<n;i++){
			if(num[i]>mx){
				mx=num[i];
				if(num[i]>num[i+1])
					ans++;
			}
		}
		if(num[n]>mx)
			ans++;
		printf("Case #%d: %d\n",k-t,ans);
	}
}