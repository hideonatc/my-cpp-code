#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
int main(){
	int t;
	cin>>t;
	int m[200010];
	for(int w=1;w<=t;w++){
		int n,k,a,b;
		int flag;
		cin>>n>>k>>a;
		int mx=-1,s_mx=-1;
		for(int i=2;i<=n;i++){
			cin>>b;
			m[i]=b-a;
			if(m[i]>mx){
				s_mx=mx;
				mx=m[i];
				flag=i;
			}
			else if(m[i]>s_mx){
				s_mx=m[i];
			}
			a=b;
		}
		int ans=max(mx-mx/2,s_mx);
		for(int j=1;j<k;j++){
			m[flag]/=2;
			m[++n]=mx-m[flag];
			ans=max(mx-mx/2,s_mx);
			printf("mx=%d s_mx=%d\n",mx,s_mx);
			if(ans==0){
				ans=1;
				break;
			}
			mx=-1,s_mx=-1;
			for(int i=2;i<=n;i++){
				if(m[i]>mx){
					s_mx=mx;
					mx=m[i];
					flag=i;
				}
				else if(m[i]>s_mx){
					s_mx=m[i];
				}
			}
		}
		printf("Case #%d: %d",w,ans);
		cout<<endl;
	}
}