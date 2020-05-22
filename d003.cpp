#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
void dp(string s_1,string s_2){
	char ans[25]={'0'};
	bool flag=false;
	int l1 = s_1.length();
	int l2 = s_2.length();
	int label[25][25]={0};
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s_1[i-1]==s_2[j-1])label[i][j]=label[i-1][j-1]+1;
			else label[i][j]=max(label[i-1][j],label[i][j-1]);
		}
	}
	int l=label[l1][l2],t=l;
	int i=l1;
	for(;i>=1;){
		for(int j=l2;j>=1;){
			if(t==1+label[i-1][j]&&t==1+label[i][j-1]&&t==label[i][j]){
				ans[l]=s_2[j-1];
				l--;
				i--;
				j--;
				t--;
				flag=1;
				//printf("(%d,%d)\n",i,j);
			}
			if(flag) break;
			else j--;
		}
		if(flag)flag=0;
		else i--;
	}
	cout<<s_1<<" "<<s_2<<" = ";
	for(int i=1;i<=label[l1][l2];i++)cout<<ans[i];
	if(label[l1][l2]==0)cout<<0;
	cout<<endl;
}
int main(){
	int i=3;
	while(i--){
		string s1,s2;
		cin>>s1>>s2;
		dp(s1,s2);
	}
}
