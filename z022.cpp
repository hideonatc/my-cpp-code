#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int m[6],ans=0;
		for(int i=0;i<6;i++)
			cin>>m[i];
		for(int i=0;i<6;i++){
			int k;
			cin>>k;
			for(int j=0;j<6;j++)
				if(m[j]>k)
					ans++;
		}
		cout<<ans<<endl;
	}
}