#include<iostream>
using namespace std;
void solve(int t){
	bool p=false;
	for(int i=1;i*i<t;i++){
		for(int j=i;i*i+j*j<t;j++){
			for(int m=j;i*i+j*j+m*m<t;m++){
				for(int n=m;i*i+j*j+m*m+n*n<=t;n++){
					int sum=i*i+j*j+m*m+n*n;
					if(sum==t){
						p=true;
						printf("%d %d %d %d\n",i,j,m,n);
					}
				}
			}
		}
	}
	if(!p)
		cout<<"0"<<endl;
	return;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		int arg=1;
		for(int i=1;i<=k;i++)
			arg*=2;
		solve(arg);
	}
}