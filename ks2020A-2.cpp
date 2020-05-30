#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int e=1;e<=t;e++){
		int n,k,p;
		cin>>n>>k>>p;
		int dp[51][1501]={0};
		int sum[51][51]={0};
		for(int i=1;i<=n;i++){
			int q;
			for(int j=1;j<=k;j++){
				cin>>q;
				sum[i][j]=sum[i][j-1]+q;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=p;j++){
				for(int f=0;f<=min(j,k);f++){
					dp[i][j]=max(dp[i][j],dp[i-1][j-f]+sum[i][f]);
				}
			}
		}
		printf("Case #%d: %d",e,dp[n][p]);
		cout<<endl;
	}
}