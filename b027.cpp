#include<iostream>
using namespace std;
int map[102][102];
int x,y;
int ans=1;
bool expend(int a,int b,int n){
	for(int i=a;i<a+n;i++)
		if(map[i][b+n-1]==1)
			return 0;
	for(int i=b;i<b+n;i++)
		if(map[a+n-1][i]==1)
			return 0;
	return 1;	
}
void solve(){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(map[i][j])
				continue;
			int n=2;
			while(expend(i,j,n++))
				if(n-1>ans)
					ans=n-1;
		}
	}
}
int main(){
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=x+1;i++)
		map[i][y+1]=1;
	for(int i=1;i<=y+1;i++)
		map[x+1][i]=1;
	solve();
	cout<<ans*ans<<endl;
}