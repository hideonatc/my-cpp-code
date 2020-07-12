#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string tar,in;
		cin>>tar>>in;
		int ans;
		if(tar[0]!=tar[2]||tar.length()>3)
			ans=-1;
		else{
			ans=0;
			for(int i=0;i<in.length()-2;i++){
				bool flag=0;
				for(int j=0;j<3;j++)
					if(tar[j]!=in[i+j]){
						flag=1;
						break;
					}
				if(!flag)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
}