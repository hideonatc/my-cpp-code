#include<iostream>
using namespace std;
bool ck(int a){
	for(int i=2;i<=a/2;i++){
		if(a%i==0)
			return 0;
	}
	return 1;
}
void solve(int a){
	for(int i=2;i<=a;i++){
		bool ans=false;
		if(ck(i)){
			ans=true;
			int k=i;
			string s="";
			while(k>0){
				s+=char(k%10-int('0'));
				k/=10;
			}
			int l=s.length();
			if(l%2==0){
				for(int j=0;j<=l/2;j++)
					if(s[j]!=s[l-j-1]){
						ans=false;
						break;
					}
			}
			else{
				for(int j=0;j<l/2;j++)
					if(s[j]!=s[l-j-1]){
						ans=false;
						break;
					}
			}
		}
		if(ans)
			cout<<i<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	solve(n);
	cout<<endl;
}