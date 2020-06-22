#include<iostream>
using namespace std;
int m[11][11];
int ans1(int a){
	int ans=0,mx;
	for(int i=1;i<=a;i++){
		mx=-1;
		for(int j=1;j<=a;j++){
			if(m[i][j]>mx)
				mx=m[i][j];
		}
		ans+=mx;
	}
	return ans;
}
int ans2(int a){
	int ans=0,mx;
	for(int i=1;i<=a;i++){
		mx=-1;
		for(int j=1;j<=a;j++){
			if(m[j][i]>mx)
				mx=m[j][i];
		}
		ans+=mx;
	}
	return ans;
}
int a3=-1;
bool used[11]={0};
void ans3(int a,int n,int s){
	if(a+1==n){
		if(s>a3)
			a3=s;
		return;
	}
	else{
		bool b=false;
		for(int i=1;i<=a;i++){
			if(!used[i]){
				b=true;
				used[i]=true;
				ans3(a,n+1,s+m[n][i]);
				used[i]=false;
			}
		}
		if(!b)
			return;
	}
}
int main(){
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>m[i][j];
		printf("第%d組測試資料結果\n",k);
		printf("(1) 讓所有先生都最滿意的「速配程度」總分為%d分\n",ans1(n));
		printf("(2) 讓所有小姐都最滿意的「速配程度」總分為%d分\n",ans2(n));
		ans3(n,1,0);
		printf("(3) 完滿結局最高「速配程度」總分為%d分\n",a3);
		cout<<endl;
	}
}