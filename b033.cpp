#include<iostream>
using namespace std;
void solve(string s1,string s2){
	int l1=s1.length(),l2=s2.length();
	s1='0'+s1;
	s2='0'+s2;
	int ans[102][102];
	for(int i=0;i<=l1;i++)
		ans[i][0]=0;
	for(int j=0;j<=l2;j++)
		ans[0][j]=0;
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i]==s2[j]){
				ans[i][j]=ans[i-1][j-1]+1;
			}
			else{
				ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
			}
		}
	}
	/*for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}*/
	cout<<ans[l1][l2]<<endl;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	solve(s2,s1);
}