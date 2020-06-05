#include<iostream>
#include<algorithm>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
bool compare(int a,int b){
	return a>b;
}
int main(){
	int t;
	cin>>t;
	int m[200010][2]={0},m2[200010];
	for(int w=1;w<=t;w++){
		int n,k,a,b;
		cin>>n>>k>>a;
		int mx=-1,s_mx=-1;
		for(int i=1;i<n-1;i++){
			cin>>b;
			m[i]=b-a;
			a=b;
		}
		sort(m2,m2+n-1,compare);
		for(int i=0,k=1;i<n-1;i++){
			while(m2[i]==m2[i+1]){
				m[k][0]=m2[i];
				m[k][1]++;
				i++;
			}
			k++;
		}
		int ans;
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
		}
		printf("Case #%d: %d",w,ans);
		cout<<endl;
	}
}